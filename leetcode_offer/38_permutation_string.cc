// 面试题38. 字符串的排列
// 输入一个字符串，打印出该字符串中字符的所有排列。
// 
//  
// 
// 你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。
// 
//  
// 
// 示例:
// 
// 输入：s = "abc"
// 输出：["abc","acb","bac","bca","cab","cba"]
//  
// 
// 限制：
// 
// 1 <= s 的长度 <= 8

class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> ans;
        if (s.empty()) return ans;
        sort(s.begin(), s.end());
        vector<bool> visited(s.size(), false);
        string curr;
        
        permutation(s, curr, visited, ans);
        return ans;
    }
private:
    void permutation(const string &s, string &curr, 
                     vector<bool> &visited, 
                     vector<string> &ans) {
        if (curr.size() == s.size()) {
            ans.push_back(curr);
            return;
        }
        
        for (size_t i = 0; i < s.size(); ++i) {
            if (visited[i]) continue;
            if (i > 0 && s[i] == s[i - 1] && !visited[i - 1]) continue;
            
            curr.push_back(s[i]);
            visited[i] = true;
            permutation(s, curr, visited, ans);
            visited[i] = false;
            curr.pop_back();
        }
    }
};
