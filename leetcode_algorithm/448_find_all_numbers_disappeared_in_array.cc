class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (auto num : nums)
            nums[abs(num) - 1] = -abs(nums[abs(num) - 1]);
        
        vector<int> ans;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) ans.push_back(i + 1);
        }
        return ans;
    }
    
//      vector<int> findDisappearedNumbers(vector<int>& nums) {
//         for (size_t i = 0; i < nums.size(); ++i) {
//             int num = nums[i];
//             if (num == i + 1) continue;
            
//             nums[i] = 0;
//             while (num != 0 && nums[num-1] != num) {
//                 int next = nums[num-1];
//                 nums[num-1] = num;
//                 num = next;
//             }
//         }
        
//         vector<int> ans;
//         for (size_t i = 0; i < nums.size(); ++i) {
//             if (nums[i] == 0) ans.push_back(i + 1);
//         }
//         return ans;
//     }
};
