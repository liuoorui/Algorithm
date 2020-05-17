class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> str_set;
        string curr;
        
        int max_length = 0;
        int left_num = 0;
        for (char ch : s) {
            if (ch == '(') {
                ++left_num;
            } else if (ch == ')') {
                if (left_num > 0) {
                    --left_num;
                    max_length += 2;
                }
            } else {
                ++max_length;
            }
        }
        
        dfs(s, 0, curr, max_length, 0, str_set);
        return vector<string>(str_set.begin(), str_set.end());
    }
private:
    inline void dfs(const string& s, size_t idx, string& curr, int max_length, 
             int left_num, unordered_set<string>& coll) {
        if (0 > left_num) return;
        if (s.size() == idx) {
            if (0 == left_num && curr.size() == max_length) coll.insert(curr);
            return;
        }
        
        // 删除这个括号。
        if (('(' == s[idx] || ')' == s[idx]))
            dfs(s, idx + 1, curr, max_length, left_num, coll);
        
        // 不删除这个括号。
        if (s[idx] == '(') ++left_num;
        else if (s[idx] == ')') --left_num;
        curr.push_back(s[idx]);
        dfs(s, idx + 1, curr, max_length, left_num, coll);
        curr.pop_back();
    }
};
