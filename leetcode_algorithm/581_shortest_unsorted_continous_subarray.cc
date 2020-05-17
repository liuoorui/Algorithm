class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // O(n).
        int low = -1, high = -2;
        int min = INT_MAX, max = INT_MIN;
        
        for (size_t i = 0; i < nums.size(); ++i) {
            int rev = nums.size() - 1 - i;
            
            if (nums[i] < max) high = i;
            else max = nums[i];
            
            if (nums[rev] > min) low = rev;
            else min = nums[rev];
        }
        
        return high - low + 1;
    }
    
//     int findUnsortedSubarray(vector<int>& nums) {
//         // O(nlogn).
//         vector<int> sorted(nums.cbegin(), nums.cend());
//         sort(nums.begin(), nums.end());
        
//         size_t l = 0, r = nums.size() - 1;
//         while (l < nums.size() && nums[l] == sorted[l]) ++l;
//         while (r > l && nums[r] == sorted[r]) --r;
        
//         return r < l? 0 : r - l + 1;
//     }
};
