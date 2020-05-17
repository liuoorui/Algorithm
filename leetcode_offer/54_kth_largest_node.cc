// 面试题54. 二叉搜索树的第k大节点
// 给定一棵二叉搜索树，请找出其中第k大的节点。
// 
//  
// 
// 示例 1:
// 
// 输入: root = [3,1,4,null,2], k = 1
//    3
//   / \
//  1   4
//   \
//    2
// 输出: 4
// 示例 2:
// 
// 输入: root = [5,3,6,2,4,null,null,1], k = 3
//        5
//       / \
//      3   6
//     / \
//    2   4
//   /
//  1
// 输出: 4
//  
// 
// 限制：
// 
// 1 ≤ k ≤ 二叉搜索树元素个数

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 递归
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        int cnt = k;
        return traverse(root, cnt)->val;
    }
private:
    const TreeNode* traverse(const TreeNode *root, int &cnt) {
        if (!root) return nullptr;
        
        auto right = traverse(root->right, cnt);
        if (right) return right;
        if (--cnt == 0) return root;
        return traverse(root->left, cnt);
    }
};

// 迭代
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        const TreeNode *curr = root;
        stack<const TreeNode*> stk;

        while (curr || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->right;
            }

            curr = stk.top();
            stk.pop();
            if (--k == 0) break;
            curr = curr->left;
        }
        return curr->val;
    }
};
