#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty()) return res;
        unordered_map<string, int> words_map;
        int num = words.size(), word_leng = words[0].size(), 
            str_leng = num * word_leng, beg = 0, end = str_leng;

        for (string word: words) ++words_map[word];

        while (end <= s.size()) {
            unordered_map<string, int> curr_map;
            int k = 0;

            while (k < str_leng) {
                string substr = s.substr(beg+k, word_leng);
                
                if (words_map.find(substr) != 
                    words_map.end()) {
                    ++curr_map[substr];
                    if (curr_map[substr] > words_map[substr])
                        break;
                    k += word_leng;
                } else {
                    break;
                }
            }

            if (k == str_leng) res.push_back(beg);
            ++beg;
            ++end;
        }

        return res;
    }
};