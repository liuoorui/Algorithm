class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary(): root(new Node()){
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto curr = root;
        
        for (auto ch : word) {
            int idx = ch - 'a';
            
            if (curr->nexts[idx] == nullptr) {
                curr->nexts[idx] = new Node();
            }
            curr = curr->nexts[idx];
        }
        
        ++curr->cnt;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(root, word);
    }
    
private:
    struct Node {
        Node* nexts[26];
        int cnt;
        Node(): cnt(0) {
            memset(nexts, 0, 26 * sizeof(Node*));
        }
    };
    bool search(const Node* root, const string& word) {
        if (!root) return false;
        auto curr = root;
        
        for (size_t i = 0; i < word.size(); ++i) {
            char ch = word[i];
            
            if (ch == '.') {
                auto substr = word.substr(i + 1);
                for (size_t j = 0; j < 26; ++j) {
                    if (search(curr->nexts[j], substr))
                        return true;
                }
                return false;
            } else {
                int idx = ch - 'a';
                if (curr->nexts[idx] == nullptr)
                    return false;
                curr = curr->nexts[idx];
            }
        }
        
        return curr->cnt > 0;
    }
    
    Node* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
