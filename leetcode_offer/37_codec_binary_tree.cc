// 面试题37. 序列化二叉树
// 请实现两个函数，分别用来序列化和反序列化二叉树。
// 
// 示例: 
// 
// 你可以将以下二叉树：
// 
//     1
//    / \
//   2   3
//      / \
//     4   5
// 
// 序列化为 "[1,2,3,null,null,4,5]"
// 注意：本题与主站 297 题相同：https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/

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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        queue<TreeNode*> que;
        if (root) que.push(root);
        
        while (!que.empty()) {
            auto curr = que.front();
            que.pop();
            
            if (curr) {
                data += to_string(curr->val) + ',';
                que.push(curr->left);
                que.push(curr->right);
            } else {
                data += "null,";
            }
        }
        
        if (!data.empty()) data.pop_back();
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        unique_ptr<TreeNode> dummy(new TreeNode(0));
        queue<TreeNode*> que;
        que.push(dummy.get());
        size_t beg = 0, end = 0;
        bool left_side = false;
        
        while (beg < data.size()) {
            while (end < data.size() && data[end] != ',') ++end;
            auto str = data.substr(beg, end - beg);
            TreeNode *node = nullptr;
            if (str != "null") node = new TreeNode(atoi(str.c_str()));
            
            auto curr = que.front();
            if (left_side) {
                curr->left = node;
            } else {
                curr->right = node;
                que.pop();
            }
            
            if (node) que.push(node);
            left_side = !left_side;
            beg = ++end;
        }
        
        return dummy->right;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
