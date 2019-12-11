class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (size_t i = 0; i < equations.size(); ++i) {
            auto& elem = equations[i];
            
            if (umap.find(elem[0]) == umap.end())
                umap[elem[0]] = new Node;
            if (umap.find(elem[1]) == umap.end())
                umap[elem[1]] = new Node;
            join(umap[elem[0]], umap[elem[1]], values[i]);
        }
        
        vector<double> ans(queries.size());
        for (size_t i = 0; i < queries.size(); ++i) {
            auto& first = queries[i][0];
            auto& second = queries[i][1];
            if (umap.find(first) == umap.end() || umap.find(second) == umap.end() || 
                find(umap[first]) != find(umap[second])) {
                ans[i] = -1;
            } else {
                ans[i] = umap[first]->value / umap[second]->value;
            }
        }
        
        return ans;
    }
    
private:   
    struct Node {
        double  value;
        Node*   pre;
        Node(): value(1), pre(this) {}
    };
    
    Node* find(Node* node) {
        if (node->pre == node) return node;
        return find(node->pre);
    }
    
    void join(Node* n1, Node* n2, double value) {
        auto pre1 = find(n1);
        auto pre2 = find(n2);
        if (pre1 == pre2) return;
        
        double ratio = n1->value / (n2->value * value);
        for (auto& elem : umap) {
            if (find(elem.second) == pre2) {
                elem.second->value *= ratio;
            }
        }
        pre2->pre = pre1;
    }
    
    unordered_map<string, Node*> umap;
};
