#include <iostream>
#include <stack>
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
    void recoverTree(TreeNode* root) {
        // 中序遍历顺序找到不符合升序的两个；
        TreeNode *pre = NULL, *curr = root,
            *first = NULL, *second = NULL;
        stack<TreeNode*> s;
        
        while (curr || !s.empty()) {
            while (curr) {
                s.push(curr);
                curr = curr->left;
            }
            
            curr = s.top();
            s.pop();
            
            if (pre && curr->val<pre->val) {
                if (!first) {
                    first = pre;
                    // 一点小技巧，如果是相邻两个换位的话则找不到之后循环时候的if条件
                    second = curr; 
                } else {
                    second = curr;
                    break;
                }
            }
            pre = curr;
            
            curr = curr->right;
        }
        
        if (first && second) {
            int temp = first->val;
            first->val = second->val;
            second->val = temp;
        }
    }
};