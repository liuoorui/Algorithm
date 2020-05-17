// 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
// 
//  
// 
// 示例 1：
// 
// 输入：m = 2, n = 3, k = 1
// 输出：3
// 示例 1：
// 
// 输入：m = 3, n = 1, k = 0
// 输出：1
// 提示：
// 
// 1 <= n,m <= 100
// 0 <= k <= 20
// 
// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<bool> visited(m * n, false);
        int cnt = 0;
        
        dfs(m, n, k, visited, 0, 0, &cnt);
        return cnt;
    }
private:
    void dfs(int m, int n, int k, 
             vector<bool> &visited,
             int row, int col, int *cnt) {
        if (row < 0 || row >= m || col < 0 || col >= n) 
            return;
        int pos = n * row + col;
        if (visited[pos])
            return;
        if (getSum(row, col) > k) 
            return;
        
        visited[pos] = true;
        ++(*cnt);
        dfs(m, n, k, visited, row - 1, col, cnt);
        dfs(m, n, k, visited, row + 1, col, cnt);
        dfs(m, n, k, visited, row, col - 1, cnt);
        dfs(m, n, k, visited, row, col + 1, cnt);
    }
    
    int getSum(int row, int col) {
        return getSum(row) + getSum(col);
    }
    
    int getSum(int num) {
        int ans = 0;
        while (num) {
            ans += num % 10;
            num /= 10;
        }
        return ans;
    }
};
