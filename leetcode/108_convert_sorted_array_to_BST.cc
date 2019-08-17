#include <iostream>
#include <vector>
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size());
    }
private:
    TreeNode* sortedArrayToBST(vector<int>& nums, int beg, int end) {
        int leng = end - beg, idx = beg + leng/2;
        if (leng == 0) return NULL;
        TreeNode *root = new TreeNode(nums[idx]);
        
        root->left = sortedArrayToBST(nums, beg, idx);
        root->right = sortedArrayToBST(nums, idx+1, end);
        
        return root;
    }
};