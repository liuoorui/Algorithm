// 314. 二叉树的垂直遍历
// 给定一个二叉树，返回其结点 垂直方向（从上到下，逐列）遍历的值。
// 
// 如果两个结点在同一行和列，那么顺序则为 从左到右。
// 
// 示例 1：
// 
// 输入: [3,9,20,null,null,15,7]
// 
//    3
//   /\
//  /  \
// 9   20
//     /\
//    /  \
//   15   7 
// 
// 输出:
// 
// [
//   [9],
//   [3,15],
//   [20],
//   [7]
// ]
// 示例 2:
// 
// 输入: [3,9,8,4,0,1,7]
// 
//      3
//     /\
//    /  \
//   9    8
//   /\   /\
//  /  \ /  \
// 4   0 1   7 
// 
// 输出:
// 
// [
//   [4],
//   [9],
//   [3,0,1],
//   [8],
//   [7]
// ]
// 示例 3:
// 
// 输入: [3,9,8,4,0,1,7,null,null,null,2,5]（注意：0 的右侧子节点为 2，1 的左侧子节点为 5）
// 
//      3
//     /\
//    /  \
//    9   8
//   /\  /\
//  /  \/  \
//  4  01   7
//     /\
//    /  \
//    5   2
// 
// 输出:
// 
// [
//   [4],
//   [9,5],
//   [3,0,1],
//   [8,2],
//   [7]
// ]

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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        // 按照层次遍历的顺序遍历。
        // 记录节点对应的列号，将结果写入对应的列。
        map<int, vector<int>> col_map;
        queue<pair<const TreeNode *, int>> que; // pair存放节点和对应的列值。
        if (root) que.push(make_pair<const TreeNode *, int>(root, 0));
        
        while (!que.empty()) {
            auto curr = que.front().first;
            auto col = que.front().second;
            que.pop();
            
            col_map[col].push_back(curr->val);
            if (curr->left) 
                que.push(make_pair<const TreeNode *, int>(curr->left, col - 1));
            if (curr->right) 
                que.push(make_pair<const TreeNode *, int>(curr->right, col + 1));
        }
        
        vector<vector<int>> ans(col_map.size());
        size_t idx = 0;
        for (auto &elem : col_map) {
            ans[idx++] = std::move(elem.second);
        }
        return ans;
    }
};
