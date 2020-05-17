// 面试题35. 复杂链表的复制
// 请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。
// 
//  
// 
// 示例 1：
// 
// 
// 
// 输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
// 输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
// 示例 2：
// 
// 
// 
// 输入：head = [[1,1],[2,1]]
// 输出：[[1,1],[2,1]]
// 示例 3：
// 
// 
// 
// 输入：head = [[3,null],[3,0],[3,null]]
// 输出：[[3,null],[3,0],[3,null]]
// 示例 4：
// 
// 输入：head = []
// 输出：[]
// 解释：给定的链表为空（空指针），因此返回 null。
//  
// 
// 提示：
// 
// -10000 <= Node.val <= 10000
// Node.random 为空（null）或指向链表中的节点。
// 节点数目不超过 1000 。
//  
// 
// 注意：本题与主站 138 题相同：https://leetcode-cn.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        // 复制节点
        auto curr = head;
        while (curr) {
            auto new_node = new Node(curr->val);
            new_node->next = curr->next;
            curr->next = new_node;
            curr = new_node->next;
        }
        
        // 复制 random 指针。
        curr = head;
        while (curr) {
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        
        // 分离链表。
        unique_ptr<Node> dummy(new Node(0));
        auto copyed_tail = dummy.get();
        curr = head;
        while (curr) {
            copyed_tail->next = curr->next;
            copyed_tail = curr->next;
            
            curr->next = curr->next->next;
            curr = curr->next;
        }
        return dummy->next;
    }
};
