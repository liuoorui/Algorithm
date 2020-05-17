class Solution {
public:
    string largestNumber(vector<int>& nums) {    
        vector<string> strs(nums.size());
        for (size_t i = 0; i < nums.size(); ++i) {
            strs[i] = to_string(nums[i]);
        }
        
        sort(strs.begin(), strs.end(), [](string lhs, string rhs)->bool{
            auto temp = lhs;
            lhs += rhs;
            rhs += temp;
            return lhs > rhs;
            
        });
        
        string ans;
        for (const auto& str : strs) {
            ans += str;
        }
        size_t beg = 0;
        while (beg < ans.size() - 1 && ans[beg] == '0') ++beg;
        return ans.substr(beg, ans.size() - beg);
    }
};
