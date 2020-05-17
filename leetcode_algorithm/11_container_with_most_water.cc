#include <iostream>
#include <vector>
using namespace std;

class Solution {
public: 
    int maxArea(vector<int>& height) {
        int max_area = 0, l = 0, r = height.size()-1;

        while (l < r) {
            int dist = r - l, min_height;

            if (height[l] < height[r]) min_height = height[l++];
            else min_height = height[r--];

            max_area = max(max_area, dist * min_height);
        }

        return max_area;
    }
};

int main() {
    int n, i = 0, res;
    cout<<"input length of array: ";
    cin>>n;
    vector<int> height(n);
    while (n--) cin>>height[i++];

    Solution solu;
    res = solu.maxArea(height);

    cout<<"max area: "<<res<<endl;
}