// 面试题40. 最小的k个数
// 输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。
// 
//  
// 
// 示例 1：
// 
// 输入：arr = [3,2,1], k = 2
// 输出：[1,2] 或者 [2,1]
// 示例 2：
// 
// 输入：arr = [0,1,2,1], k = 1
// 输出：[0]
//  
// 
// 限制：
// 
// 0 <= k <= arr.length <= 1000
// 0 <= arr[i] <= 1000

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        partition(arr, 0, arr.size(), k);
        vector<int> ans(arr.cbegin(), arr.cbegin() + k);
        return ans;
    }
private:
    void partition(vector<int> &arr, int beg, int end, int k) {
        if (beg >= end) return;
        int l = beg, r = end;
        int q = arr[beg];
        
        while (true) {
            do ++l; while (l < r && arr[l] < q);
            do --r; while (arr[r] > q);
            
            if (l >= r) break;
            swap(arr[l], arr[r]);
        }
        
        swap(arr[beg], arr[r]);
        if (r > k - 1) partition(arr, beg, r, k);
        else if (r < k - 1) partition(arr, r + 1, end, k);
    }
};
