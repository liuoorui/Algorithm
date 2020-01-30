class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
        for (auto num : nums) {
            diff ^= num;
        }
        
        diff = diff & (~diff + 1);
        int a = 0, b = 0;
        for (auto num : nums) {
            if (num & diff) a ^= num;
            else b ^= num;
        }
        
        return vector<int>{a, b};
    }
};
