#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> map;
        int ans = 0;
        
        for (int num: nums) {
            if (map[num] != 0) continue;
            
            int left = map[num-1], right = map[num+1];
            int leng = 1 + left + right;
            map[num] = leng;
            
            if (left != 0) map[num-left] = leng;
            if (right != 0) map[num+right] = leng;
        }
        
        for (auto elem: map) 
            ans = max(ans, elem.second);
        
        return ans;
    }
};