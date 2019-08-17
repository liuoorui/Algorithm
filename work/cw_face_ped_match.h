#ifndef CW_FACE_PED_MATCH_H_
#define CW_FACE_PED_MATCH_H_

#include <vector>
#include <tuple>
#include <algorithm>

#define BATCH_SIZE 200
#define THRESHOLD_MATCH_SCORE 0
#define THRESHOLD_BOX_SCORE 0
#define FACE_VALUE 4
#define PED_VALUE 1

struct FPM_Point {
	float x;
	float y;
	FPM_Point() { x = 0; y = 0; };
	FPM_Point(float _x, float _y) { x = _x; y = _y; };
	FPM_Point& operator=(const FPM_Point& rhs) {
		x = rhs.x;  y = rhs.y;
		return *this;
	}
	FPM_Point& operator-=(const FPM_Point& rhs) {
	    x -= rhs.x;
	    y -= rhs.y;
	    return *this;
	}
}; // struct FPM_Point

inline FPM_Point operator-(FPM_Point _a, const FPM_Point &_b) {
    _a -= _b;
    return _a;
}

struct FPM_Box {
    FPM_Point left_up;
    FPM_Point right_dn;

    FPM_Box(FPM_Point lu, FPM_Point rd) {
        left_up = lu;
        right_dn = rd;
    }
    FPM_Box() = default;
    FPM_Box& operator=(const FPM_Box& rhs) {
        left_up = rhs.left_up;  right_dn = rhs.right_dn;
        return *this;
    }

    int Contains(const FPM_Point &point) const;
    bool Contains(const FPM_Box &box) const;
    void SetBox(const float *poses);
    FPM_Box GetLocalCoordinate(const FPM_Box &parents) const;
}; // struct FPM_Box


class Matcher {
public:
    Matcher() {
        used_ = new bool[100];
    }
    ~Matcher() {
        delete[] used_;
    }
//Function:
//  匹配一个图片中的检测框
//Parameter:
//  [IN] boxes: 100 * 4
//  [IN] score: 100
//  [IN] classes: 100
//  [IN] count
//  [OUT] matched_pairs: 50 * 3，匹配对(face_index, ped_index, score)，需要传入前分配空间。
//  [OUT] matched_count: 1，表示实际匹配对数量，需要传入前分配空间。
    void MatchSinglePic(const float *boxes, const float *scores, const int *classes,
                        int count, float *matched_pairs, int *matched_count);

//Function:
//  MatchBatch: 匹配一个BATCH图片中的检测框
//Parameter:
//  [IN] boxes: batch_size * 100 * 4，四个值分别为(leftup.x, leftup.y, rightdn.x, rightdn.y)，均为未归一化的绝对坐标
//  [IN] scores: batch_size * 100
//  [IN] classes: batch_size * 100
//  [IN] count: batch_size * 1
//  [OUT] matched_pairs: batch_size * 50 * 3，匹配对(face_index, ped_index, score)，需要传入前分配空间。
//  [OUT] matched_count: batch_size * 1, 表示实际匹配对数量，需要传入前分配空间。
//  [IN] batch_size: 用来处理数据最后一批数量可能小于BATCH_SIZE的情况。
    void MatchBatch(const float *boxes, const float *scores, const int *classes,
                    const int *counts, float *matched, int *matched_count, int batch_size = BATCH_SIZE);

private:
    std::vector<std::pair<int, int> > filtered_pairs_;
    std::vector<float> filtered_scores_;
    bool *used_;

    void CalculateScoresV1(const float *boxes);

    // TODO: CalculateScoreV2，需要更改 MatchScore 函数
    float MatchScore(const FPM_Box &face, const FPM_Box &ped);
    void Assign(const std::vector<std::pair<int, int> > &pairs, const std::vector<float> &scores,
            float *matched_pairs, int *matched_counts) const;

}; // class Matcher

#endif  // CW_FACE_PED_MATCH_H_