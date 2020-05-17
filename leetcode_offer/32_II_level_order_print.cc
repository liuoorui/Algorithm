// 面试题32 - II. 从上到下打印二叉树 II
// 从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
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
// 返回其层次遍历结果：
// 
// [
//   [3],
//   [9,20],
//   [15,7]
// ]
//  
// 
// 提示：
// 
// 节点总数 <= 1000
// 注意：本题与主站 102 题相同：https://leetcode-cn.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        levelOrder(root, 0, ans);
        
        return ans;
    }
private:
    void levelOrder(const TreeNode *root, size_t level, 
                    vector<vector<int>> &ans) {
        if (!root) return;
        if (level >= ans.size()) ans.push_back(vector<int>());
        
        ans[level].push_back(root->val);
        levelOrder(root->left, level + 1, ans);
        levelOrder(root->right, level + 1, ans);
    }
};
