class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        if (total % 2 == 0)
            return static_cast<double>(findKSortedArray(nums1, nums2, total/2) + 
                                       findKSortedArray(nums1, nums2, total/2 + 1)) / 2;
        else
            return findKSortedArray(nums1, nums2, total/2 + 1);
    }
private:
    int findKSortedArray(const vector<int> &nums1, const vector<int> &nums2, int k) {
        // 寻找第k小的数字；
        int m = nums1.size(), n = nums2.size();
        int beg1 = 0, beg2 = 0;
        
        while (k > 1) {
            cout << "k = " << k << endl;
            int u = k / 2;
            if (beg1 == m) return nums2[beg2 + k - 1];
            if (beg2 == n) return nums1[beg1 + k - 1];
            if (beg1 + u > m) u = m - beg1;
            else if (beg2 + u > n) u = n - beg2;
            
            if (nums1[beg1 + u - 1] < nums2[beg2 + u - 1])
                beg1 += u;
            else
                beg2 += u;
            k -= u;
        }
        
        if (beg1 >= m) return nums2[beg2];
        if (beg2 >= n) return nums1[beg1];
        return min(nums1[beg1], nums2[beg2]);
    }
};