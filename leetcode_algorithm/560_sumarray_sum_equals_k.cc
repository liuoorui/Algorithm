class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        int cnt = 0;
        int curr_sum = 0;
        
        umap[0] = 1;
        for (auto num : nums) {
            curr_sum += num;
            auto iter = umap.find(curr_sum - k);
            if (iter != umap.end())
                cnt += iter->second;
            
            ++umap[curr_sum];
        }
        
        return cnt;
    }
};
