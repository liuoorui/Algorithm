// 面试题34. 二叉树中和为某一值的路径
// 输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。
// 
//  
// 
// 示例:
// 给定如下二叉树，以及目标和 sum = 22，
// 
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1
// 返回:
// 
// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]
//  
// 
// 提示：
// 
// 节点总数 <= 10000
// 注意：本题与主站 113 题相同：https://leetcode-cn.com/problems/path-sum-ii/

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> path;
        
        backtrack(root, sum, path, ans);
        return ans;
    }
private:
    void backtrack(const TreeNode *root, int sum, 
             vector<int> &path, vector<vector<int>> &ans) {
        if (!root) return;
        if (!root->left && !root->right) {
            if (sum == root->val) {
                ans.push_back(path);
                ans.back().push_back(root->val);
            }
            return;
        }
        
        path.push_back(root->val);
        backtrack(root->left, sum - root->val, path, ans);
        backtrack(root->right, sum - root->val, path, ans);
        path.pop_back();
    }
};
