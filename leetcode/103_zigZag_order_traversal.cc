#include <iostream>
#include <vector>
#include <queue>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        int cnt = 1, level = 0;
        if (root) q.push(root);
        
        while (!q.empty()) {
            int nextCnt = 0, sign = level++%2==0? 0: 1;
            vector<int> vec(cnt);
            TreeNode *curr;
            
            while (cnt--) {
                curr = q.front();
                q.pop();
                
                if (curr->left) {q.push(curr->left); ++nextCnt;}
                if (curr->right) {q.push(curr->right); ++nextCnt;}
                
                if (sign) vec[cnt] = curr->val; // 逆序
                else vec[vec.size()-cnt-1] = curr->val;
            }
            
            ans.push_back(vec);
            cnt = nextCnt;
        }
        
        return ans;
    }
};