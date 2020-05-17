#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        
        while (i < j) {
            while (i<j && !isalnum(s[i])) ++i;
            while (i<j && !isalnum(s[j])) --j;
            
            if (i >= j) return true;
            if (s[i++] != s[j--]) return false;
        }
        
        return true;
    }
};