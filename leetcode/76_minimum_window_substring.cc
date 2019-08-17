#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        unordered_map<char, int> map;
        int min_leng = INT_MAX, begin = 0, cnt = 0, l = 0, r = 0;

        for (char ch: t) ++map[ch];

        while (r < s.size()) {
            if (map.find(s[r]) != map.end()) {
                if (--map[s[r]] >= 0) ++cnt;

                while (cnt == t.size()) {
                    if (map.find(s[l]) != map.end()) {
                        int curr_leng = r - l + 1;
                        if (curr_leng < min_leng) {
                            min_leng = curr_leng;
                            begin = l;
                        }

                        if (++map[s[l]] > 0) --cnt;
                    }

                    ++l;
                }
            }
            
            ++r;
        }

        if (min_leng == INT_MAX) return "";
        else return s.substr(begin, min_leng);
    }
};