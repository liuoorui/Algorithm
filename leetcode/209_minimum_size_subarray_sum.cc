class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int min_len = INT_MAX;
        size_t beg = 0, end = 0;
        int curr_sum = 0;
        
        while (end <= nums.size()) {
            if (curr_sum < s) {
                if (end < nums.size())
                    curr_sum += nums[end];
                ++end;
            } else {
                min_len = min(min_len, static_cast<int>(end - beg));
                curr_sum -= nums[beg++];
            }
        }
        
        return min_len == INT_MAX? 0 : min_len;
    }
};
