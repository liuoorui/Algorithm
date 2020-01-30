class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (lheap_.empty() || num < lheap_.front()) {
            pushHeap(lheap_, num, 0);
        } else {
            pushHeap(rheap_, num, 1);
        }
    }
    
    double findMedian() {
        while (lheap_.size() > rheap_.size() + 1) {
            pushHeap(rheap_, popHeap(lheap_, 0), 1);
        }
        while (lheap_.size() < rheap_.size()) {
            pushHeap(lheap_, popHeap(rheap_, 1), 0);
        }
        
        if (lheap_.empty())
            return 0;
        else if (lheap_.size() == rheap_.size()) 
            return (lheap_.front() + rheap_.front()) / 2.0;
        else
            return lheap_.front();
    }
private: 
    void pushHeap(vector<int> &heap, int num, int flag = 0) {
        heap.push_back(num);
        if (flag == 0)
            push_heap(heap.begin(), heap.end()); // big root
        else
            push_heap(heap.begin(), heap.end(), std::greater<int>()); // small root
    }
    
    int popHeap(vector<int> &heap, int flag = 0) {
        if (flag == 0) {
            pop_heap(heap.begin(), heap.end());
        } else {
            pop_heap(heap.begin(), heap.end(), std::greater<int>());
        }
        
        int num = heap.back();
        heap.pop_back();
        return num;
    }
    
    vector<int> lheap_;
    vector<int> rheap_;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
