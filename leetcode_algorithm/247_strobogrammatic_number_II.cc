// 247. 中心对称数 II
// 中心对称数是指一个数字在旋转了 180 度之后看起来依旧相同的数字（或者上下颠倒地看）。
// 
// 找到所有长度为 n 的中心对称数。
// 
// 示例 :
// 
// 输入:  n = 2
// 输出: ["11","69","88","96"]

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> ans;
        if (n <= 0) return ans;
        
        unordered_map<char, char> umap{
            {'0', '0'}, {'1', '1'}, {'6', '9'}, 
            {'8', '8'}, {'9', '6'}
        };
        char *str = (char*)malloc((n + 1) * sizeof(char));
        str[n] = 0;
        dfs(umap, str, 0, n, ans);
        
        free(str);
        return ans;
    }
    
private:
    void dfs(unordered_map<char, char> &umap, 
             char *str, int idx, int n, vector<string> &ans) {
        if ((n % 2 == 0 && idx == n / 2)
            || (n % 2 != 0 && idx > n / 2)) {
            ans.push_back(str);
            return;
        }
        vector<char> chars{'1', '6', '8', '9', '0'};
        if (n % 2 != 0 && idx == n / 2) {
            // 奇数长度中间位置。
            chars = vector<char>{'1', '8', '0'};
        }
        if (idx == 0 && n != 1) chars.pop_back();
        
        for (char ch : chars) {
            // printf("idx: %d, ch: %c, %s\n", idx, ch, str);
            str[idx] = ch;
            str[n - idx - 1] = umap[ch];
            dfs(umap, str, idx + 1, n, ans);
        }
    }
};
