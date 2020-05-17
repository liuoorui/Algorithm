class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 摩尔投票法。
        int cnt = 0;
        int tar;
        
        for (int num : nums) {
            if (cnt == 0) {
                tar = num;
                ++cnt;
                continue;
            }
            
            cnt += (num == tar)? 1 : -1;
        }
        
        return tar;
    }
    
    // int majorityElement(vector<int>& nums) {
    //     // 暴力法。
    //     sort(nums.begin(), nums.end());
    //     return nums[nums.size()/2];
    // }
};