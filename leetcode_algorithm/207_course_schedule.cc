class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 由于需要大量进行删除，因此拷贝到链表中操作。
        int depends[numCourses] = { 0 };
        list<pair<int, int>> list_requisites;

        for (const auto& elem : prerequisites) {
            ++depends[elem[0]];
            list_requisites.push_back(pair<int, int>{elem[0], elem[1]});
        }
        
        bool flag = false;
        while (!list_requisites.empty()) {
            flag = false;
            auto iter = list_requisites.begin();
            while (iter != list_requisites.end()) {
                auto& elem = *iter;

                if (depends[elem.second] == 0) {
                    // 处理迭代器失效。
                    auto temp = iter;
                    ++temp;
                    
                    --depends[elem.first];
                    list_requisites.erase(iter);
                    flag = true;
                    
                    iter = temp;
                } else {
                    ++iter;
                }
            }
            
            if (!flag) return false;
        }
        
        return true;
    }
};