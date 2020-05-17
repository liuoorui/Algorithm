class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        inStack_.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int front = peek();
        outStack_.pop();
        
        return front;
    }
    
    /** Get the front element. */
    int peek() {
        if (outStack_.empty()) {
            while (!inStack_.empty()) {
                outStack_.push(inStack_.top());
                inStack_.pop();
            }
        }
        
        return outStack_.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return inStack_.empty() && outStack_.empty();
    }
    
private:
    stack<int> inStack_;
    stack<int> outStack_;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
