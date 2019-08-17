#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // 将dp优化到一维；
        // 从右向左加可以不影响上一轮的值；
        vector<int> ans(rowIndex+1);
        
        for (int i=0; i<=rowIndex; ++i) {
            for (int j=i; j>=0; --j) {
                if (j==0 || i==j)
                    ans[j] = 1;
                else
                    ans[j] += ans[j-1];
            }
        }
        
        return ans;
    }
};