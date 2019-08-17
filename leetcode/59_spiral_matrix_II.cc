#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        if (n <= 0) return res;
        int i = 0, j = 0, u = n-1, v = n-1, idx = 1, k;
        
        while (idx <= n*n) {
            for (k=j; k<=v; ++k) res[i][k] = idx++;
            ++i;
            
            if (j > v) break;
            for (k=i; k<=u; ++k) res[k][v] = idx++;
            --v;
            
            if (i > u) break;
            for (k=v; k>=j; --k) res[u][k] = idx++;
            --u;
            
            if (j > v) break;
            for (k=u; k>=i; --k) res[k][j] = idx++;
            ++j;
        }
        
        return res;
    }
};