class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        vector<int> is_prime(n, true);
        
        for (int i = 2; i < n; ++i) {
            if (!is_prime[i]) continue;
            
            ++cnt;
            for (int j = 2 * i; j < n; j += i) {
                is_prime[j] = false;
            }
        }
        
        return cnt;
    }
};
