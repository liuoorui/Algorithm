#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        
        for (int i=0; i<haystack.size(); ++i) {
            int j = 0;
            while (j < needle.size()) {
                if (haystack[i+j] != needle[j])
                    break;
                ++j;
            }
            
            if (j == needle.size()) return i;
        }
        
        return -1;
    }
};