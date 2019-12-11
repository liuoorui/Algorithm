class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans = (numerator > 0 && denominator < 0 || 
                      numerator < 0 && denominator > 0) ? "-" : "";
        unordered_map<int, int> umap;
        long quotient = 0;
        auto long_numerator = abs(static_cast<long>(numerator));
        auto long_denominator = abs(static_cast<long>(denominator));

        quotient = long_numerator / long_denominator;
        long_numerator %= long_denominator;
        ans += to_string(quotient); 
        if (long_numerator == 0) return ans;
        ans.push_back('.');
        
        while (long_numerator != 0) {
            long_numerator *= 10;
            quotient = long_numerator / long_denominator;
            auto iter = (umap.find(long_numerator));
            if (iter != umap.end()) {
                int pos = iter->second;
                ans.insert(ans.begin() + pos, '(');
                ans.push_back(')');
                break;
            }
            
            umap[long_numerator] = ans.size();
            long_numerator %= long_denominator;
            ans.push_back('0' + quotient);
        }
        
        return ans;
    }
};
