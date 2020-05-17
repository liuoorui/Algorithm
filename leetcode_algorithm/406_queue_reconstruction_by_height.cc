class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // Sort by h, k.
        sort(people.begin(), people.end(), [](const auto& lhs, const auto& rhs) { 
            return lhs[0] > rhs[0] || (lhs[0] == rhs[0] && lhs[1] < rhs[1]);
        });
        
        // Use linked list.
        list<vector<int>> queue;
        for (const auto& elem : people) {
            moveToKth(queue, elem);
        }
        
        return vector<vector<int>>(queue.begin(), queue.end());
    }
    
private:
    using IterType = list<vector<int>>::iterator;
    
    inline void moveToKth(list<vector<int>>& queue, const vector<int>& elem) {
        int k = elem[1];
        
        IterType pos = queue.begin();
        while (pos != queue.end() && k--) ++pos;
        queue.insert(pos, elem);
    }
};