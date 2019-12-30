class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        size_t beg = 0, end = beg;
        
        while (beg < nums.size()) {
            while (++end < nums.size() && 
                   nums[end] == nums[end - 1] + 1);
            
            if (end - beg == 1) {
                ans.push_back(to_string(nums[beg]));
            } else {
                ans.push_back(to_string(nums[beg]) + 
                              "->" + to_string(nums[end - 1]));
            }
            beg = end;
        }
        
        return ans;
    }
};
