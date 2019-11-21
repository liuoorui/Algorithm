/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // 层次遍历迭代解法。也可以用前序中序遍历递归来做。
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        if (!root) return ans;
        queue<const TreeNode*> que;
        que.push(root);
        
        while (!que.empty()) {
            const TreeNode* curr = que.front();
            que.pop();
            
            if (curr) {
                ans += to_string(curr->val) + ",";
                que.push(curr->left);
                que.push(curr->right);
            } else {
                ans += "n,";
            }
        }
        
        ans.pop_back();
        while (!ans.empty() && ans.back() == 'n')
            ans.erase(ans.end() - 2, ans.end());
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        size_t beg = 0;
        TreeNode* root = getNextNode(data, beg);
        queue<TreeNode*> que;
        que.push(root);
        
        while (!que.empty()) {
            TreeNode* curr = que.front();
            que.pop();
            
            curr->left = getNextNode(data, beg);
            curr->right = getNextNode(data, beg);
            
            if (curr->left) que.push(curr->left);
            if (curr->right) que.push(curr->right);
        }
        
        return root;
    }
    
private:
    inline TreeNode* getNextNode(const string& data, size_t& beg) {
        if (beg >= data.size()) return nullptr;
        TreeNode* new_node = nullptr;
        size_t end = beg + 1;
        
        if (data[beg] != 'n') {
            while (end < data.size() && data[end] != ',') ++end;
            new_node = new TreeNode(atoi(data.substr(beg, end - beg).c_str()));
        }
        beg = ++end;
        return new_node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
