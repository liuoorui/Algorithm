// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long beg = 1, end = static_cast<long>(n) + 1;
        
        while (beg < end) {
            long mid = beg + (end - beg) / 2;
            
            if (isBadVersion(mid)) end = mid;
            else beg = mid + 1;
        }
        return beg;
    }
};
