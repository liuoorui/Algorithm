// 面试题32 - I. 从上到下打印二叉树
// 从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。
// 
//  
// 
// 例如:
// 给定二叉树: [3,9,20,null,null,15,7],
// 
//     3
//    / \
//   9  20
//     /  \
//    15   7
// 返回：
// 
// [3,9,20,15,7]
//  
// 
// 提示：
// 
// 节点总数 <= 1000

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> node_queue;
        if (root) node_queue.push(root);
        
        while (!node_queue.empty()) {
            auto curr = node_queue.front();
            node_queue.pop();
            
            ans.push_back(curr->val);
            if (curr->left) node_queue.push(curr->left);
            if (curr->right) node_queue.push(curr->right);
        }
        return ans;
    }
};
