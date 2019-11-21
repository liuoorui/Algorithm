class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        size_t  size = nums.size();
        vector<int> ans(size);
        int product = 1;
        int i = 0;
        
        // forward.
        while (i < size) {
            ans[i] = product;
            product *= nums[i++];
        }
        
        // backward.
        product = 1;
        i = size - 1;
        while (i >= 0) {
            ans[i] *= product;
            product *= nums[i--];
        }
        
        return ans;
    }
};
