class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        
        while (n) {
            int remainder = (n - 1) % 26;
            n = (n - 1) / 26;
            ans.insert(ans.begin(), 'A' + remainder);
        }
        
        return ans;
    }
};
