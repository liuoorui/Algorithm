class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> uset;
        
        while (n != 1) {
            if (uset.find(n) != uset.end())
                return false;
            uset.insert(n);
            
            int next = 0;
            while (n) {
                next += pow(n % 10, 2);
                n /= 10;
            }
            n = next;
        }
        
        return true;
    }
};
