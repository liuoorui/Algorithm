class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty()) return;
        k %= nums.size();
        
        int mid = nums.size() - k;
        reverse(nums.begin(), nums.begin() + mid);
        reverse(nums.begin() + mid, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
