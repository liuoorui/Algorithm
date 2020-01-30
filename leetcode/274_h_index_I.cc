class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), std::greater<int>());
        
        for (int i = citations.size() - 1; i >= 0; --i) {
            if (citations[i] >= i + 1) return i + 1;
        }
        return 0;
    }
};
