// 面试题41. 数据流中的中位数
// 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
// 
// 例如，
// 
// [2,3,4] 的中位数是 3
// 
// [2,3] 的中位数是 (2 + 3) / 2 = 2.5
// 
// 设计一个支持以下两种操作的数据结构：
// 
// void addNum(int num) - 从数据流中添加一个整数到数据结构中。
// double findMedian() - 返回目前所有元素的中位数。
// 示例 1：
// 
// 输入：
// ["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
// [[],[1],[2],[],[3],[]]
// 输出：[null,null,null,1.50000,null,2.00000]
// 示例 2：
// 
// 输入：
// ["MedianFinder","addNum","findMedian","addNum","findMedian"]
// [[],[2],[],[3],[]]
// 输出：[null,null,2.00000,null,2.50000]
//  
// 
// 限制：
// 
// 最多会对 addNum、findMedia进行 50000 次调用。
// 注意：本题与主站 295 题相同：https://leetcode-cn.com/problems/find-median-from-data-stream/

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() : median_(0) {

    }
    
    void addNum(int num) {
        if (num < median_) lheap_.push(num);
        else rheap_.push(num);
        
        balance();
        if (lheap_.size() == rheap_.size()) 
            median_ = static_cast<double>(lheap_.top() + rheap_.top()) / 2;
        else
            median_ = lheap_.top();
    }
    
    double findMedian() {
        return median_;
    }
private:
    void balance() {
        while (lheap_.size() > rheap_.size() + 1) {
            rheap_.push(lheap_.top());
            lheap_.pop();
        }
        while (lheap_.size() < rheap_.size()) {
            lheap_.push(rheap_.top());
            rheap_.pop();
        }
    }
    
    double median_;
    priority_queue<int, vector<int>, less<int>> lheap_;
    priority_queue<int, vector<int>, greater<int>> rheap_;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
