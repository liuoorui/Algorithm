#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct Node {
    int val;
    struct Node *left, *right;
    Node (){}
    Node (int val) {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

class binaryTree{
public:
    void insert(int val) {
        if (!root) {
            root = new Node(val);
        }
        Node *curr = root, *p;

        while (curr) {
            p = curr;
            if (val == curr->val) return;
            else if (val < curr->val) curr = curr->left;
            else curr = curr->right;
        }

        Node *node = new Node(val);
        if (val < p->val) p->left = node;
        else p->right = node;

        ++size;
    }

    // 三种遍历的非递归写法
    // 递归太简单了就不写了
    void preOrder() {
        if (!root) return;
        stack<Node*> s;
        Node *curr = root;

        cout<<"preOrder: ";
        while (curr || !s.empty()) {
            while (curr) {
                s.push(curr);
                cout<<curr->val<<" ";
                curr = curr->left;
            }

            if (!s.empty()) {
                curr = s.top();
                s.pop();
                curr = curr->right;
            }
        }
        cout<<endl;
    }

    void midOrder() {
        if (!root) return;
        stack<Node*> s;
        Node *curr = root;

        cout<<"midOrder: ";
        while (curr || !s.empty()) {
            while (curr) {
                s.push(curr);
                curr = curr->left;
            }

            if (!s.empty()) {
                curr = s.top();
                s.pop();
                cout<<curr->val<<" ";
                curr = curr->right;
            }
        }
        cout<<endl;
    }

    void postOrder() {
        if (!root) return;
        vector<int> res;
        Node *curr = root;
        stack<Node*> s;

        cout<<"postOrder: ";
        while (curr || !s.empty()) {
            while (curr) {
                res.push_back(curr->val);
                s.push(curr);
                curr = curr->right;
            }

            if (!s.empty()) {
                curr = s.top();
                s.pop();
                curr = curr->left;
            }
        }

        for (int i=res.size()-1; i>=0; --i)
            cout<<res[i]<<" ";
        cout<<endl;
    }
private:
    Node *root;
    int size;
};

int main(int argc, char const *argv[])
{
    binaryTree tree;
    tree.insert(4);
    tree.insert(2);
    tree.insert(1);
    tree.insert(3);
    tree.insert(6);
    tree.insert(5);
    tree.insert(7);

    tree.preOrder();
    tree.midOrder();
    tree.postOrder();
}
