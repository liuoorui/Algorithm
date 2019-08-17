#include "cw_face_ped_match.h"

#include <cmath>


bool CompTuples(const std::tuple<int, int, float> &t1, const std::tuple<int, int, float> &t2) {
    return std::get<2>(t1) > std::get<2>(t2);
}

int FPM_Box::Contains(const FPM_Point &point) const {
    if (point.x == -1 && point.y == -1)
        return 0;
    if (((left_up.x - 5) <= point.x)
        && ((right_dn.x + 5) >= point.x)
        && ((left_up.y - 5) <= point.y)
        && ((right_dn.y + 5) >= point.y))
        return 1;
    else
        return -10;
}

inline bool FPM_Box::Contains(const FPM_Box &box) const {
    return 2 == Contains(box.left_up) + Contains(box.right_dn);
}

inline void FPM_Box::SetBox(const float *poses) {
    left_up.x = *poses;
    left_up.y = *(poses + 1);
    right_dn.x = *(poses + 2);
    right_dn.y = *(poses + 3);
}

inline FPM_Box FPM_Box::GetLocalCoordinate(const FPM_Box &parents) const {
    // 计算脸框在行人框的局部坐标
    return FPM_Box(left_up - parents.left_up,
            right_dn - parents.left_up);
}

float Matcher::MatchScore(const FPM_Box &face, const FPM_Box &ped) {
    // 转换为行人框内局部坐标
    FPM_Box local_face = face.GetLocalCoordinate(ped);
    float height = ped.right_dn.y - ped.left_up.y;
    float width = ped.right_dn.x - ped.left_up.x;

    // 计算脸框坐标部分匹配度值
    float x1 = local_face.left_up.x / width;
    float y1 = local_face.left_up.y / height;
    float x2 = local_face.right_dn.x / width;

    float sl = -2 * (x1 - 0.1) * (x1 - 0.5);
    float sr = -3 * (x2 - 0.45) * (x2 - 0.95);
    float su;

    // 计算脸框上边缘得分，不可过低或者过高
    if (local_face.left_up.y <= 5)
        su = -0.1;
    else if (y1 < 0.3)
        su = 0.6 - powf(powf(y1 - 0.1, 2), 0.13);
    else
        su = 7 * (0.22 - y1);
    float face_score = sl + sr + su; // 脸部匹配度总得分

    // 计算脸框跨度得分
    float span_x = (local_face.right_dn.x - local_face.left_up.x) / width;
    float span_y = (local_face.right_dn.y - local_face.left_up.y) / height;
    span_x = (span_x < 0.15)? -powf(0.15 - span_x, 0.8) * 5: 0;
    span_y = (span_y < 0.08)? -powf(0.08 - span_y, 0.08) * 10: 0;
    float body_score = span_x + span_y - 1;

    // 总匹配度为脸部匹配得分加上关节点部分匹配度得分
    return face_score + body_score + 0.9;
}

// 计算方法V1计算匹配得分
void Matcher::CalculateScoresV1(const float *boxes) {
    filtered_scores_.resize(filtered_pairs_.size());

    FPM_Box face, ped;
    for (int i = 0; i < filtered_pairs_.size(); ++i) {
        face.SetBox(boxes + 4 * filtered_pairs_[i].first);
        ped.SetBox(boxes + 4 * filtered_pairs_[i].second);

        filtered_scores_[i] = MatchScore(face, ped);
    }
}

void Matcher::Assign(const std::vector<std::pair<int, int> > &pairs, const std::vector<float> &scores,
        float *matched_pairs, int *matched_counts) const {
    // 先对索引对和得分中得分小于0的过滤
    // 然后按照得分降序排列
    // 按照得分降序依次选择不重复的索引对
    int count = 0;
    memset(used_, false, sizeof(bool)*100);
    std::vector<std::tuple<int, int, float> > tuples;

    for (int i = 0; i < filtered_pairs_.size(); ++i) {
        if (filtered_scores_[i] <= THRESHOLD_MATCH_SCORE)
            continue;

        tuples.emplace_back(filtered_pairs_[i].first, filtered_pairs_[i].second, filtered_scores_[i]);
    }

    // 按照score降序排列
    std::sort(tuples.begin(), tuples.end(), CompTuples);

    // 分配
    int face_index, ped_index;
    for (const auto &elem: tuples) {
        face_index = std::get<0>(elem);
        ped_index = std::get<1>(elem);

        // 检测框已经被高分的匹配对用过
        if (used_[face_index] || used_[ped_index])
            continue;

        used_[face_index] = true;
        used_[ped_index] = true;

        matched_pairs[3 * count] = face_index;
        matched_pairs[3 * count + 1] = ped_index;
        matched_pairs[3 * count + 2] = std::get<2>(elem);
        ++count;
    }

    *matched_counts = count;
}

void Matcher::MatchSinglePic(const float *boxes, const float *scores, const int *classes, int count,
        float *matched_pairs, int *matched_counts) {
    filtered_pairs_.clear();
    filtered_scores_.clear();

    int *face_indexes = new int[100];
    int *ped_indexes = new int[100];
    int face_count = 0, ped_count = 0;

    // 将检测框索引按照脸框和行人框种类分开
    for (int i = 0; i < count; ++i) {
        // 过滤置信度过低的检测框
        if (scores && scores[i] < THRESHOLD_BOX_SCORE)
            continue;

        if (classes[i] == FACE_VALUE)
            face_indexes[face_count++] = i;
        else if (classes[i] == PED_VALUE)
            ped_indexes[ped_count++] = i;
    }

    // 判断并将行人框包含脸框的索引对保存
    FPM_Box face, ped;
    for (int i = 0; i < face_count; ++i) {
        for (int j = 0; j < ped_count; ++j) {
            face.SetBox(boxes + 4 * face_indexes[i]);
            ped.SetBox(boxes + 4 * ped_indexes[j]);
            if (!ped.Contains(face))
                continue;

            filtered_pairs_.emplace_back(face_indexes[i], ped_indexes[j]);
        }
    }

    delete[] face_indexes;
    delete[] ped_indexes;

    // 计算匹配对的得分。
    CalculateScoresV1(boxes);

    // 分配匹配结果。
    Assign(filtered_pairs_, filtered_scores_, matched_pairs, matched_counts);
}

void Matcher::MatchBatch(const float *boxes, const float *scores, const int *classes, const int *counts,
        float *matched, int *matched_counts, int batch_size) {
    // 区别是否传入了检测框置信度参数。
    if (scores) {
        for (int i = 0; i < batch_size; ++i) {
            MatchSinglePic(boxes + 100 * 4 * i, scores + 100 * i, classes + 100 * i,
                           counts[i], matched + 150 * i, matched_counts + i);
        }
    } else {
        for (int i = 0; i < batch_size; ++i) {
            MatchSinglePic(boxes + 100 * 4 * i, nullptr, classes + 100 * i,
                           counts[i], matched + 150 * i, matched_counts + i);
        }
    }
}