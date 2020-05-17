#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode1(int n) {
        // 根据自然数跟格雷编码的对应关系：i ^ (i>>1)
        vector<int> ans;
        
        for (int i=0; i<pow(2, n); ++i) {
            ans.push_back(i ^ (i>>1));
        }
        
        return ans;
    }

    vector<int> grayCode2(int n) {
        // 笨办法，根据上一个生成下一个，用哈希表来判断是否重复生成
        vector<int> res{0};
        unordered_set<int> set{0};
        int i = 0, num = 0;
        
        while (i < n) {
            i = 0;
            int m = 1;
            
            while (i < n) {
                int curr = num ^ m;
                m = m<<1;
                if (set.find(curr) != set.end()) {
                    ++i;
                    continue;
                }
                res.push_back(curr);
                set.insert(curr);
                num = curr;
                break;
            }
        }
        
        return res;
    }
};