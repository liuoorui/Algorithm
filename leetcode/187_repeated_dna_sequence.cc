class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<string, int> umap;
        
        for (int i = 0; i < (int)s.size() - 9; ++i) {
            auto substr = s.substr(i, 10);
            ++umap[substr];
            if (umap[substr] == 2) ans.push_back(substr);
        }
        
        return ans;
    }
};
