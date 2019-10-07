#include <iostream>
#include <stack>

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (mins_.empty() || x <= mins_.top()) {
            mins_.push(x);
        }
        
        stack_.push(x);
    }
    
    void pop() {
        if (stack_.empty())
            return;
        
        if (stack_.top() == mins_.top())
            mins_.pop();
        stack_.pop();
    }
    
    int top() {
        return stack_.top();
    }
    
    int getMin() {
        return mins_.top();
    }
    
private:
    stack<int>  stack_;
    stack<int>  mins_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */