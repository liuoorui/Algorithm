class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, major1 = 0;
        int count2 = 0, major2 = 0;
        
        for (auto num : nums) {
            if ((count1 == 0 || major1 == num) && num != major2) {
                ++count1;
                major1 = num;
            } else if (count2 == 0 || major2 == num) {
                ++count2;
                major2 = num;
            } else {
                --count1;
                --count2;
            }
        }
        
        vector<int> ans;
        count1 = 0;
        count2 = 0;
        for (auto num : nums) {
            if (num == major1) ++count1;
            if (num == major2) ++count2;
        }
        
        if (count1 > nums.size() / 3) ans.push_back(major1);
        if (count2 > nums.size() / 3 && major2 != major1) ans.push_back(major2);
        return ans;
    }  
};
