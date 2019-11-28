class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int curr_max = 1;
        int curr_min = 1;
        
        for (auto num : nums) {
            curr_max *= num;
            curr_min *= num;
            
            if (curr_max < curr_min) 
                swap(curr_max, curr_min);
            ans = max(ans, curr_max);
            if (curr_max <= 0) curr_max = 1;
            if (curr_min >= 0) curr_min = 1;
        }
        
        return ans;
    }
};
