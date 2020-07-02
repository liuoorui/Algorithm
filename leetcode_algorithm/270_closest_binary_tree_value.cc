// 270. 最接近的二叉搜索树值
// 给定一个不为空的二叉搜索树和一个目标值 target，请在该二叉搜索树中找到最接近目标值 target 的数值。
// 
// 注意：
// 
// 给定的目标值 target 是一个浮点数
// 题目保证在该二叉搜索树中只会存在一个最接近目标值的数
// 示例：
// 
// 输入: root = [4,2,5,1,3]，目标值 target = 3.714286
// 
//     4
//    / \
//   2   5
//  / \
// 1   3
// 
// 输出: 4

class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        double dist = abs(target - root->val);
        int ans = root->val;
        const TreeNode *curr = root;
        
        while (curr) {
            if (abs(target - curr->val) <= dist) {
                dist = abs(target - curr->val);
                ans = curr->val;
            }
            if (curr->val < target) curr = curr->right;
            else if (curr->val > target) curr = curr->left;
            else return curr->val;
        }
        return ans;
    }
};
