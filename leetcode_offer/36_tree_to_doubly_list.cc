// 面试题36. 二叉搜索树与双向链表
// 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。
// 
//  
// 
// 为了让您更好地理解问题，以下面的二叉搜索树为例：
// 
//  
// 
// 
// 
//  
// 
// 我们希望将这个二叉搜索树转化为双向循环链表。链表中的每个节点都有一个前驱和后继指针。对于双向循环链表，第一个节点的前驱是最后一个节点，最后一个节点的后继是第一个节点。
// 
// 下图展示了上面的二叉搜索树转化成的链表。“head” 表示指向链表中有最小元素的节点。
// 
//  
// 
// 
// 
//  
// 
// 特别地，我们希望可以就地完成转换操作。当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。还需要返回链表中的第一个节点的指针。
// 
//  
// 
// 注意：本题与主站 426 题相同：https://leetcode-cn.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/
// 
// 注意：此题对比原题有改动。

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return root;
        auto root_list = unfold(root);
        
        root_list.first->left = root_list.second;
        root_list.second->right = root_list.first;
        return root_list.first;
    }
private:
    using List = pair<Node *, Node *>;
    List unfold(Node *root) {
        if (!root) return List{nullptr, nullptr};
        List ans{root, root};
        
        auto left_list = unfold(root->left);
        auto right_list = unfold(root->right);
        if (left_list.second) {
            left_list.second->right = root;
            root->left = left_list.second;
            ans.first = left_list.first;
        }
        if (right_list.first) {
            right_list.first->left = root;
            root->right = right_list.first;
            ans.second = right_list.second;
        }
        return ans;
    }
};
