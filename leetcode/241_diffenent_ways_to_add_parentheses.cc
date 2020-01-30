class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        unordered_map<string, vector<int>> ans_map;
        unordered_map<char, function<int(int, int)>> ops;
        ops['+'] = [](int lhs, int rhs) { return lhs + rhs; };
        ops['-'] = [](int lhs, int rhs) { return lhs - rhs; };
        ops['*'] = [](int lhs, int rhs) { return lhs * rhs; };
        
        diffWaysToCompute(input, ans_map, ops);
        return ans_map[input];
    }
    
private:
    void diffWaysToCompute(string input, 
                           unordered_map<string, vector<int>> &ans_map, 
                           unordered_map<char, function<int(int, int)>> &ops) {
        // 避免重复计算。
        if (ans_map.find(input) != ans_map.end())
            return;
        
        vector<int> ans;
        int idx = 0;
        
        while (idx < input.size()) {
            if (!isdigit(input[idx])) {
                auto left_ans = diffWaysToCompute(input.substr(0, idx));
                auto right_ans = diffWaysToCompute(input.substr(idx + 1));
                auto op = ops[input[idx]];

                for (auto left : left_ans) {
                    for (auto right : right_ans) {
                        ans.push_back(op(left, right));
                    }
                }
            }

            ++idx;
        }
        
        if (ans.empty()) ans.push_back(stoi(input));
        ans_map[input] = ans;
    }
};
