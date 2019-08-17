#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        // 牛顿法
        if (x==0 || x==1) return x;
        int r = x / 2;
        
        while (true) {
            int v = x / r;
            // cout<<"r = "<<r<<" v = "<<v<<endl;
            if (r <= v) return r;
            r = (r + v)>>1;
        }
    }
    int mySqrt2(int x) {
        // 二分法
        int l = 0, r = x>46340? 46340: x, mid;

        while (l <= r) {
            mid = l + (r-l)/2;
            int v = mid * mid;

            if (v < x) l = mid + 1;
            else if (v > x) r = mid - 1;
            else return mid;
        }

        return r;
    }
};