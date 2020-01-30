class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        array<int, 10> secret_cnt, guess_cnt;
        string ans;
        memset(secret_cnt.data(), 0, sizeof(int) * secret_cnt.size());
        memset(guess_cnt.data(), 0, sizeof(int) * guess_cnt.size());
        
        for (size_t i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                ++bulls;
            } else {
                ++secret_cnt[secret[i] - '0'];
                ++guess_cnt[guess[i] - '0'];
            }
        }
        for (size_t i = 0; i < 10; ++i) {
            cows += min(secret_cnt[i], guess_cnt[i]);
        }
        
        ans += to_string(bulls) + "A" + to_string(cows) + "B";
        return ans;
    }
};
