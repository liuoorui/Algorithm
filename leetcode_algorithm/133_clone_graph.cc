#include <iostream>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (visited[node]) return visited[node];
        int cnt = node->neighbors.size();
        Node *clonedNode = new Node(node->val, vector<Node*>(cnt));
        visited[node] = clonedNode;
        
        for (int i=0; i<cnt; ++i)
            clonedNode->neighbors[i] = cloneGraph(node->neighbors[i]);
        
        return clonedNode;
    }
private:
    unordered_map<Node*, Node*> visited;
};