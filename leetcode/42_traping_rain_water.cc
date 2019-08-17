#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        return trap(height, 0, height.size()-1);
    }
private:
    int trap(vector<int>& height, int l, int r) {
        while (l<r && height[l]<=height[l+1]) ++l;
        while (r>l && height[r]<=height[r-1]) --r;
        if (l >= r) return 0;
        
        int min_h = min(height[l], height[r]),
            mid = l+1, res = 0;
        for (int i=l+1; i<r; ++i) {
            if (height[i] > height[mid]) mid = i;
            res += min_h - height[i];
        }
        
        if (height[mid] > min_h) {
            res = trap(height, l, mid) 
                + trap(height, mid, r);
        }
        
        return res;
    }
};