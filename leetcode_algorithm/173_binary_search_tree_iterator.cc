/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        while(root) {
            stk_.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        auto curr = stk_.top();
        stk_.pop();
        int value = curr->val;
        
        if (curr->right) {
            curr = curr->right;
            while (curr) {
                stk_.push(curr);
                curr = curr->left;
            }
        }
        
        return value;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk_.empty();
    }
    
private:
    stack<const TreeNode*> stk_;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
