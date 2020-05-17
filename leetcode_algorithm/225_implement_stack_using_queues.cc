class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        queue_in_.push(x);
        while (!queue_out_.empty()) {
            queue_in_.push(queue_out_.front());
            queue_out_.pop();
        }
        
        queue_in_.swap(queue_out_);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top = queue_out_.front();
        queue_out_.pop();
        return top;
    }
    
    /** Get the top element. */
    int top() {
        return queue_out_.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return queue_out_.empty();
    }
    
private:
    queue<int> queue_in_;
    queue<int> queue_out_;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
