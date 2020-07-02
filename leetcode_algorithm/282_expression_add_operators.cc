// 282. 给表达式添加运算符
// 给定一个仅包含数字 0-9 的字符串和一个目标值，在数字之间添加二元运算符（不是一元）+、- 或 * ，返回所有能够得到目标值的表达式。
// 
// 示例 1:
// 
// 输入: num = "123", target = 6
// 输出: ["1+2+3", "1*2*3"] 
// 示例 2:
// 
// 输入: num = "232", target = 8
// 输出: ["2*3+2", "2+3*2"]
// 示例 3:
// 
// 输入: num = "105", target = 5
// 输出: ["1*0+5","10-5"]
// 示例 4:
// 
// 输入: num = "00", target = 0
// 输出: ["0+0", "0-0", "0*0"]
// 示例 5:
// 
// 输入: num = "3456237490", target = 9191
// 输出: []

const char OPERATORS[3] = {'*', '+', '-'};
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<int> vals;
        vector<char> ops;
        vector<string> ans;
        
        for (size_t end = 1; end <= num.size(); ++end) {
            if (num[0] == '0' && end > 1) break;
            int val = atoi(num.substr(0, end - 0).c_str());
            if (val < 0) break; // 溢出。
            
            vals.push_back(val);
            dfs(num, target, end, val, val, vals, ops, ans);
            vals.pop_back();
        }
        return ans;
    }
private:
    void dfs(const string &num, int target, size_t idx, 
             long long int curr, long long int pre,
             vector<int> &vals, vector<char> &ops, 
             vector<string> &ans) {
        if (idx == num.size()) {
            if (curr == target) {
                string str = to_string(vals[0]);
                for (size_t i = 0; i < ops.size(); ++i) {
                    str.push_back(ops[i]);
                    str += to_string(vals[i + 1]);
                }
                ans.push_back(str);
            }
            return;
        }
        
        for (size_t end = idx + 1; end <= num.size(); ++end) {
            // 这里就是普通的回溯思路。
            if (num[idx] == '0' && end - idx > 1) break;
            int val = atoi(num.substr(idx, end - idx).c_str());
            if (val < 0) break;
            for (int i = 0; i < 3; ++i) {
                long long int _curr = curr;
                long long int _pre = pre;
                
                if (OPERATORS[i] == '*') {
                    _curr -= _pre;
                    _pre *= val;
                } else if (OPERATORS[i] == '+') {
                    _pre = val;
                } else {
                    _pre = -val;
                }
                
                _curr += _pre;
                // printf("idx: %d, curr: %d, pre: %d, val: %d, op: %c\n", 
                //        idx, curr, pre, val, OPERATORS[i]);
                vals.push_back(val);
                ops.push_back(OPERATORS[i]);
                dfs(num, target, end, _curr, _pre, vals, ops, ans);
                vals.pop_back();
                ops.pop_back();
            }
        }
    }
};
