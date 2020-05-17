// 面试题32 - III. 从上到下打印二叉树 III
// 请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。
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
//   [20,9],
//   [15,7]
// ]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        levelOrder(root, 0, ans);
        for (size_t i = 1; i < ans.size(); i += 2) {
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
private:
    void levelOrder(const TreeNode *root, size_t idx, 
                    vector<vector<int>> &ans) {
        if (!root) return;
        if (idx >= ans.size()) ans.push_back(vector<int>());
        
        ans[idx].push_back(root->val);
        levelOrder(root->left, idx + 1, ans);
        levelOrder(root->right, idx + 1, ans);
    }
};
