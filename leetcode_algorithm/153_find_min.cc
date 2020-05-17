class Solution {
public:
    int findMin(vector<int>& nums) {
        return findMin(nums, 0, nums.size());
    }
private:
    int findMin(const vector<int>& nums, int beg, int end) {
        if (beg >= end) return INT_MAX;
        if (beg + 1 == end) return nums[beg];
        int mid = beg + (end - beg) / 2;
        
        if (nums[beg] < nums[end - 1]) return nums[beg];
        else return min(findMin(nums, beg, mid), 
                        findMin(nums, mid, end));
    }
};
