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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if (n == 0) return res;
        
        res = generateTrees(1, n);
        
        return res;
    }
private:
    vector<TreeNode*> generateTrees(int l, int r) {
        vector<TreeNode*> res;
        if (l > r) return vector<TreeNode*>{NULL};
        
        for (int k=l; k<=r; ++k) {
            vector<TreeNode*> lefts = generateTrees(l, k-1),
                            rights = generateTrees(k+1, r);
            
            for (auto& left: lefts)
                for (auto& right: rights) {
                    TreeNode *node = new TreeNode(k);
                    
                    node->left = left;
                    node->right = right;
                    
                    res.push_back(node);
                }
        }
        
        return res;
    }
};