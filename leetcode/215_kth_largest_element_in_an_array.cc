class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (k > nums.size() || k < 1) return 0;
        partition(nums, 0, nums.size(), k - 1);
        return nums[k - 1];
    }
private:
    void partition(vector<int>& nums, int beg, int end, int idx) {
        // 快排的思路；
        // 但是只排到将第idx个元素放到位置就返回。
        if (beg >= end) return;
        int l = beg;
        int r = end;
        int q = nums[l];
        
        while (true) {
            do ++l; while (l < end && nums[l] > q);
            do --r; while (nums[r] < q);
            
            if (l >= r) break;
            swap(nums[l], nums[r]);
        }
        swap(nums[beg], nums[r]);
        
        if (r < idx) partition(nums, r + 1, end, idx);
        else if (r > idx) partition(nums, beg, r, idx);
    }
};
