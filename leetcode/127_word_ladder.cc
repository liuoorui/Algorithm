class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> word_set(wordList.cbegin(), wordList.cend());
        if (word_set.find(endWord) == word_set.end()) return 0;
        unordered_set<string> beg_set{ beginWord };
        unordered_set<string> end_set{ endWord };
        int cnt = 1;
        
        while (!beg_set.empty()) {
            unordered_set<string> tmp_set;
            ++cnt;
            
            for (const auto& str : beg_set) 
                word_set.erase(str);
            for (auto str : beg_set) {
                for (size_t i = 0; i < str.size(); ++i) {
                    char orig = str[i];
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        str[i] = ch;
                        if (word_set.find(str) == word_set.end()) 
                            continue;
                        if (end_set.find(str) != end_set.end()) 
                            return cnt;
                        tmp_set.insert(str);
                    }
                    str[i] = orig;
                }
            }
            
            beg_set.swap(tmp_set);
            if (beg_set.size() > end_set.size())
                beg_set.swap(end_set);
        }
        
        return 0;
    }
};
