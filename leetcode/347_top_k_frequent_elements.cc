class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.empty()) return nums;
        unordered_map<int, int> nums_map;
        for (auto num : nums) {
            ++nums_map[num];
        }
        
        vector<int> ans(k);
        int idx = 0;
        auto comp = [&nums_map] (auto lhs, auto rhs) 
                    { return nums_map[lhs] > nums_map[rhs]; };
        
        for (const auto& elem : nums_map) {
            if (idx < k) {
                ans[idx++] = elem.first;
                if (idx == k) {
                    make_heap(ans.begin(), ans.end(), comp);
                }
            } else {
                int top = ans[0];

                if (elem.second > nums_map[top]) {
                    pop_heap(ans.begin(), ans.end(), comp);
                    ans.back() = elem.first;
                    push_heap(ans.begin(), ans.end(), comp);
                }
            }
        }
        
        sort_heap(ans.begin(), ans.end(), comp);
        return ans;
    }
};
