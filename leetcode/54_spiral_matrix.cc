#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) return res;
        int i = 0, j = 0, 
            m = matrix.size()-1, n = matrix[0].size()-1;
        
        while (i<=m && j<=n) {
            int k;
            for (k=j; k<=n; ++k) res.push_back(matrix[i][k]);
            ++i;
            
            if (i > m) break;
            for (k=i; k<=m; ++k) res.push_back(matrix[k][n]);
            --n;
            
            if (j > n) break;
            for (k=n; k>=j; --k) res.push_back(matrix[m][k]);
            --m;
            
            if (i > m) break;
            for (k=m; k>=i; --k) res.push_back(matrix[k][j]);
            ++j;
        }
        
        return res;
    }
};

int main() {
    Solution solu;
    vector<vector<int>> matrix{{1,2,3},{4,5,6},{7,8,9}};
    vector<int> res;

    res = solu.spiralOrder(matrix);

    for (int x: res) cout<<x<<", ";
    cout<<endl;
}