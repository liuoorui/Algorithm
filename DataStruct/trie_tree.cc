#include <iostream>
using namespace std;

struct Node {
    struct Node* nexts[26];
    int cnt;
    Node () {
        cnt = 0;
        for (int i=0; i<26; ++i)
            nexts[i] = nullptr;
    }
};

class TrieTree {
public:
    TrieTree() {
        root = new Node();
    }

    void addWord(char* word) {
        if (!root) TrieTree();
        Node *curr = root;
        int i = 0;
        
        while (word[i] != 0) {
            Node *next = curr->nexts[word[i]-'a'];
            if (next) {
                curr = next;
            } else {
                curr->nexts[word[i]-'a'] = new Node();
                curr = curr->nexts[word[i]-'a'];
            }
            ++i;
        }

        ++(curr->cnt);
    }

    void getWordsByPrefix(char* word) {
        if (!root) return;
        Node *curr = root;
        int i = 0;

        while (word[i] != 0) {
            if (!curr->nexts[word[i]-'a']) return;

            curr = curr->nexts[word[i]-'a'];
            ++i;
        }

        printAllFromNode(curr, word);
    }
private:
    Node *root;

    void printAllFromNode(Node* node, char* word) {
        if (!node) return;
        if (node->cnt > 0) {
            int i = 0;
            cout<<word<<"\t"<<node->cnt<<endl;
        }

        int size = strlen(word);
        for (int i=0; i<26; ++i) {
            char ch = 'a' + i;
            char *added_word = (char*) malloc((size+1)*sizeof(char));
            
            strcpy(added_word, word);
            strcat(added_word, &ch);
            
            printAllFromNode(node->nexts[i], added_word);
        }
    }
};

int main() {
    TrieTree *trie = new TrieTree();

    cout<<"1: add word"<<endl;
    cout<<"2: find words by prefix"<<endl;
    cout<<"q: quit"<<endl;
    while (1) {
        char word[256];
        char ins;
        
        cout<<"input the instruction: ";
        cin>>ins;
        if (ins == 'q') break;
        cout<<"input the word: ";
        cin>>word;
        cout<<"ins = "<<ins<<" word = "<<word<<endl;

        if (ins == '1') trie->addWord(word);
        else if (ins == '2') trie->getWordsByPrefix(word);
        else cout<<endl;
    }
}