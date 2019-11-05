class Trie {
public:
    /** Initialize your data structure here. */
    Trie() : nexts{ nullptr }, count(0){
        
    }
    
    ~Trie() {
        // 析构。
        for (size_t i= 0; i < 27; ++i) {
            if (nexts[i]) delete nexts[i];
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie*   curr = this;
        size_t  idx = 0;
        
        for (char ch : word) {
            idx = ch - 'a';
            
            if (!curr->nexts[idx]) {
                curr->nexts[idx] = new Trie();
            }
            curr = curr->nexts[idx];
        }
        ++curr->count;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* last = getLast(word);
        return last && last->count > 0;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* last = getLast(prefix);
        return last;
    }

private:
    Trie* getLast(string prefix) {
        // 两个查询逻辑一样的，提取出来单独写在这里。
        Trie*   curr = this;
        size_t  idx = 0;
        
        for (char ch : prefix) {
            idx = ch - 'a';

            if (!curr->nexts[idx]) {
                return nullptr;
            }
            curr = curr->nexts[idx];
        }
        
        return curr;
    }
    
    Trie*   nexts[27];
    int     count;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
