// 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
// 
//  
// 
// 例如，给出
// 
// 前序遍历 preorder = [3,9,20,15,7]
// 中序遍历 inorder = [9,3,15,20,7]
// 返回如下的二叉树：
// 
//     3
//    / \
//   9  20
//     /  \
//    15   7
//  
// 
// 限制：
// 
// 0 <= 节点个数 <= 5000
// 
//  
// 
// 注意：本题与主站 105 题重复：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// 
// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, inorder, 
                         preorder.cbegin(), preorder.cend(), 
                         inorder.cbegin(), inorder.cend());
    }
private:
    using Iter = vector<int>::const_iterator;
    TreeNode* buildTree(const vector<int> &preorder, 
                        const vector<int> &inorder, 
                        Iter pre_beg, Iter pre_end, 
                        Iter in_beg, Iter in_end) {
        int cnt = pre_end - pre_beg;
        if (cnt == 0 || cnt != in_end - in_beg) 
            return nullptr;
        
        auto val = *pre_beg;
        auto root = new TreeNode(val);
        auto iter = find(in_beg, in_end, val);
        auto left_cnt = iter - in_beg;
        
        root->left = buildTree(preorder, inorder, 
                               pre_beg + 1, pre_beg + left_cnt + 1, 
                               in_beg, iter);
        root->right = buildTree(preorder, inorder, 
                                pre_beg + left_cnt + 1, pre_end, 
                                iter + 1, in_end);
        return root;
    }
};
