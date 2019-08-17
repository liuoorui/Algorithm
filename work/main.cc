#include "cw_face_ped_match.h"
#include "cnpy.h" // 用于读取.npz格式数据

#include <stdlib.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#define IMAGE_WIDTH 640
#define IMAGE_HEIGHT 640

// 用于测试npz格式数据集
size_t ReadFromNPZ(const std::string &file_path, std::vector<float> *pvec_boxes,
                std::vector<int> *pvec_classes, std::vector<int> *pvec_counts) {
    auto npz_boxes = cnpy::npz_load(file_path, "boxes");
    auto npz_classes = cnpy::npz_load(file_path ,"classes");
    auto npz_counts = cnpy::npz_load(file_path, "counts");

    const size_t num = npz_counts.num_vals;
    pvec_boxes->resize(4 * 100 * num);
    pvec_classes->resize(100 * num);
    pvec_counts->resize(num);

    auto *pboxes = npz_boxes.data<int32_t>();
    auto *pclasses = npz_classes.data<int8_t>();
    auto *pcounts = npz_counts.data<int64_t>();

    for (size_t i = 0; i < pvec_boxes->size(); ++i)
        (*pvec_boxes)[i] = (float)pboxes[i];
    for (size_t i = 0; i < pvec_classes->size(); ++i)
        (*pvec_classes)[i] = (int)pclasses[i];
    for (size_t i = 0; i < pvec_counts->size(); ++i)
        (*pvec_counts)[i] = (int)pcounts[i];

    return num;
}

// 用于测试几个固定CSV格式的数据集
size_t ReadFromCSV(const std::string file_name, std::vector<std::string> *pics_name,
        std::vector<float> *pvec_boxes, std::vector<int> *pvec_classes, std::vector<int> *pvec_count,
        std::vector<std::pair<int, int> > *pvec_matched_pairs, std::vector<int> *pvec_matched_count) {
    int pic_index = -1, box_index = 0;
    std::fstream file_in(file_name, std::ios::in);
    std::string line_str, str, pic_name_pre, pic_name;
    std::vector<std::string> line_array;

    while (std::getline(file_in, line_str)) {
        line_array.clear();
        std::stringstream ss(line_str);

        // 每一行各列分别为：picname, h, w, face_lefttop_x, face_lefttop_y, face_rightdn_x, face_rightdn_y, ismatch?(1/-1)
        while (std::getline(ss, str, ',')) {
            line_array.push_back(str);
        }

        pic_name = line_array[0];
        if (pic_name != pic_name_pre) {
            // 处理新的一张图片
            ++pic_index;
            box_index = 0;
            pics_name->push_back(pic_name);

            pvec_boxes->resize(pvec_boxes->size() + 100 * 4);
            pvec_classes->resize(pvec_classes->size() + 100);
            pvec_count->push_back(1);
            pvec_matched_count->push_back(0);

            // 行人框
            (*pvec_boxes)[100 * 4 * pic_index + 4 * box_index] = 0;
            (*pvec_boxes)[100 * 4 * pic_index + 4 * box_index + 1] = 0;
            (*pvec_boxes)[100 * 4 * pic_index + 4 * box_index + 2] = (float)atof(line_array[2].c_str());
            (*pvec_boxes)[100 * 4 * pic_index + 4 * box_index + 3] = (float)atof(line_array[1].c_str());

            (*pvec_classes)[100 * pic_index + box_index] = PED_VALUE;
            ++box_index;
            pic_name_pre = pic_name;
        }

        // 人脸框
        (*pvec_boxes)[100 * 4 * pic_index + 4 * box_index] = (float)atof(line_array[3].c_str());
        (*pvec_boxes)[100 * 4 * pic_index + 4 * box_index + 1] = (float)atof(line_array[4].c_str());
        (*pvec_boxes)[100 * 4 * pic_index + 4 * box_index + 2] = (float)atof(line_array[5].c_str());
        (*pvec_boxes)[100 * 4 * pic_index + 4 * box_index + 3] = (float)atof(line_array[6].c_str());

        (*pvec_classes)[100 * pic_index + box_index] = FACE_VALUE;
        ++pvec_count->back();

        // 保存匹配结果
        if (line_array[7][0] == '1') {
            pvec_matched_pairs->push_back(std::pair<int, int>{0, box_index});
            ++(pvec_matched_count->back());
        }
        ++box_index;
    }

    return (size_t)pic_index + 1;
}

float CalculatePrecision(const std::vector<std::pair<int, int> > &vec_matched_pairs, const std::vector<int> &vec_matched_count,
        const float *matched, const int *matched_count) {
    if (vec_matched_count.empty()) return 0;

    int num_total = 0, num_correct = 0;
    int num_compared = 0;
    const float *pmatched = matched;  // 指向当前位置的指针，用来取值

    for (int i = 0; i < BATCH_SIZE; ++i) {
        pmatched = matched + 150 * i;
        int count = matched_count[i];

        for (int j = 0; j < count; ++j) {
            auto beg = vec_matched_pairs.begin() + num_compared;
            auto end = vec_matched_pairs.begin() + num_compared + vec_matched_count[i];

            std::pair<int, int> curr{*(pmatched+1), *(pmatched)};
            if (std::find(beg, end, curr) != end)
                ++num_correct;

            ++num_total;
            pmatched += 3;
        }
        num_compared += vec_matched_count[i];
    }

    return (float)num_correct / num_total;
}


int main() {
    // 准备数据
    std::string file_path = "../data/12重庆地铁站.csv";
//    std::string file_path = "../data/subway.csv";
//    std::string file_path = "../data/3地铁.csv";
//    std::string file_path = "../data/13车站.csv";
//    std::string file_path = "../data/liftGate.csv";
//    std::string file_path = "../data/oneFace.csv";
//
//    std::string file_path = "../data/dataForMatch.npz";

    std::vector<float> vec_boxes;
    std::vector<std::string> pics_name;
    std::vector<int> vec_classes, vec_count, vec_matched_count;
    std::vector<std::pair<int, int> > vec_matched_pairs;
    size_t num_pics;

    num_pics = ReadFromCSV(file_path, &pics_name, &vec_boxes, &vec_classes, &vec_count, &vec_matched_pairs, &vec_matched_count);
//    num_pics = ReadFromNPZ(file_path, &vec_boxes, &vec_classes, &vec_count);

    // 设置要传入的指针参数
    const size_t batch_size = num_pics;
    float *boxes = &vec_boxes[0];
    int *classes = &vec_classes[0], *count = &vec_count[0];
    int *matched_count = new int[batch_size * 1];
    float *matched = new float[batch_size * 50 * 3];

    // 匹配
    Matcher matcher;
    matcher.MatchBatch(boxes, nullptr, classes, count, matched, matched_count, batch_size);

    // 打印匹配结果
    for (size_t i = 0; i < batch_size; ++i) {
        printf("%dth pic, %d pairs:\n", (int)i, matched_count[i]);
        for (size_t j = 0; j < matched_count[i]; ++j) {
            float *ptr = matched + 150 * i + 3 * j;
            printf("\tface: %d,\tped: %d, \tscore: %f\n", (int)ptr[0], (int)ptr[1], ptr[2]);
        }
    }

    // 计算准确率
    float precision = CalculatePrecision(vec_matched_pairs, vec_matched_count, matched, matched_count);
    std::cout << "precision = " << precision << std::endl;

    delete[] matched_count;
    delete[] matched;
}
