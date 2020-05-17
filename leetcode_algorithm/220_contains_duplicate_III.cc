class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long> k_set;
        size_t i = 0, j = 0;
        
        while (j < nums.size()) {
            if (j - i > k) {
                k_set.erase(nums[i++]);
            }
            
            // 维护一个k大小的multiset。
            // 以O(log k)的时间复杂度查找两边。
            auto iter = k_set.insert(nums[j]);
            auto iter_left = iter, iter_right = iter;
            --iter_left, ++iter_right;
            if (iter != k_set.begin() && *iter - *iter_left <= t) 
                return true;
            if (iter_right != k_set.end()&& *iter_right - *iter <= t) 
                return true;
            ++j;
        }
        
        return false;
    }
};
