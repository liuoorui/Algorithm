class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int beg = 0, end = nums.size();
        
        while (beg + 1 < end) {
            int mid = beg + (end - beg) / 2;
            if (nums[mid - 1] > nums[mid]) end = mid;
            else beg = mid;
        }
        
        return beg;
    }
};
