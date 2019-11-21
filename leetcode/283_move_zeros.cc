class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        size_t size = nums.size();
        size_t idx_zero = 0;
        size_t idx_num = 0;
        
        while (true) {
            while (idx_zero < size && nums[idx_zero] != 0) ++idx_zero;
            while (idx_num < size && nums[idx_num] == 0) ++idx_num;

            if (idx_zero == size || idx_num == size) break;
            if (idx_zero > idx_num) ++idx_num;
            else swap(nums[idx_zero], nums[idx_num]);
        }
    }
};
