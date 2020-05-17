class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> uset;
        int i = 0, j = 0;
        
        while (j < nums.size() && j <= k) {
            if (uset.find(nums[j]) != uset.end())
                return true;
            uset.insert(nums[j]);
            ++j;
        }
        while (j < nums.size()) {
            uset.erase(nums[i++]);
            if (uset.find(nums[j]) != uset.end())
                return true;
            uset.insert(nums[j]);
            ++j;
        }
        
        return false;
    }
};
