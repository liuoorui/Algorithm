// 面试题33. 二叉搜索树的后序遍历序列
// 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
// 
//  
// 
// 参考以下这颗二叉搜索树：
// 
//      5
//     / \
//    2   6
//   / \
//  1   3
// 示例 1：
// 
// 输入: [1,6,3,2,5]
// 输出: false
// 示例 2：
// 
// 输入: [1,3,2,6,5]
// 输出: true
//  
// 
// 提示：
// 
// 数组长度 <= 1000

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return verifyPostorder(postorder, 0, postorder.size());
    }
private:
    bool verifyPostorder(vector<int> &postorder, int beg, int end) {
        if (beg >= end) return true;
        int idx = end - 1;
        
        while (idx > beg && postorder[idx - 1] > postorder[idx]) {
            swap(postorder[idx - 1], postorder[idx]);
            --idx;
        }
        for (int i = beg; i < idx; ++i) {
            if (postorder[i] > postorder[idx]) return false;
        }
        
        return verifyPostorder(postorder, beg, idx) && 
               verifyPostorder(postorder, idx + 1, end);
    }
};
