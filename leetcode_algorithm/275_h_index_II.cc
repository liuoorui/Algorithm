class Solution {
public:
    int hIndex(vector<int>& citations) {
        size_t beg = 0, end = citations.size();
        
        while (beg < end) {
            size_t mid = beg + (end - beg) / 2;
            
            if (citations[mid] < citations.size() - mid) beg = mid + 1;
            else end = mid;
        }
        
        return citations.size() - beg;
    }
};
