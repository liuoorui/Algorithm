class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> frequence(26, 0);
        int max_count = 1;
        
        for (auto ch : tasks) {
            ++frequence[ch - 'A'];
        }
        sort(frequence.begin(), frequence.end());
        
        int idx = 24;
        while (idx >= 0 && frequence[idx--] == frequence[25]) {
            ++max_count;
        }
        
        return max(static_cast<int>(tasks.size()), 
                   (frequence[25] - 1) * (n + 1) + max_count);
    }
};
