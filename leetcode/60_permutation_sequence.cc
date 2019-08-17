#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string res = "", candidate = "";
        for (int i=1; i<=n; ++i) candidate.push_back('0'+i);
        vector<int> factorial(n, 1);
        for (int i=2; i<n; ++i) factorial[i] = i * factorial[i-1];
        
        for (int i=n; i>=1; --i) {
            int idx = (k-1) / factorial[i-1];
            
            res.push_back(candidate[idx]);
            candidate.erase(idx, 1);
            k -= factorial[i-1] * idx;
        }
        
        return res;
    }
};