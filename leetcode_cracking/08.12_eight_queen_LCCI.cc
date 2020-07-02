// 面试题 08.12. 八皇后
// 设计一种算法，打印 N 皇后在 N × N 棋盘上的各种摆法，其中每个皇后都不同行、不同列，也不在对角线上。这里的“对角线”指的是所有的对角线，不只是平分整个棋盘的那两条对角线。
// 
// 注意：本题相对原题做了扩展
// 
// 示例:
// 
//  输入：4
//  输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
//  解释: 4 皇后问题存在如下两个不同的解法。
// [
//  [".Q..",  // 解法 1
//   "...Q",
//   "Q...",
//   "..Q."],
// 
//  ["..Q.",  // 解法 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> cur(n, string(n, '.'));
        
        cols = initArray(n);
        ldiag = initArray(2*n - 1);
        rdiag = initArray(2*n - 1);
        
        dfs(cur, 0, ans);
        
        free(cols);
        free(ldiag);
        free(rdiag);
        return ans;
    }
private:
    bool *cols, *ldiag, *rdiag;
    bool* initArray(int len) {
        bool *arr = (bool*) malloc(len * sizeof(bool));
        memset(arr, 0, len * sizeof(bool));
        return arr;
    }
    void dfs(vector<string> &cur, int idx, 
             vector<vector<string>> &ans) {
        if (idx == cur.size()) {
            ans.push_back(cur);
            return;
        }
        
        for (int j = 0; j < cur.size(); ++j) {
            int l = idx + j, r = idx + (cur.size()-1-j);
            if (cols[j] || ldiag[l] || rdiag[r]) continue;
            
            cols[j] = 1, ldiag[l] = 1, rdiag[r] = 1;
            cur[idx][j] = 'Q';
            dfs(cur, idx + 1, ans);
            cur[idx][j] = '.';
            cols[j] = 0, ldiag[l] = 0, rdiag[r] = 0;
        }
    }
};
