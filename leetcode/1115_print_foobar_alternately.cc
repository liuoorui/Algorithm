#include <mutex>
#include <thread>
#include <condition_variable>

class FooBar {
private:
    int n;
    mutex   mutex_;
    bool    foo_turn;
    condition_variable  cv_;

public:
    FooBar(int n) {
        this->n = n;
        foo_turn = true;
        cv_.notify_all();
    }

    void foo(function<void()> printFoo) {
        unique_lock<mutex>  lk(mutex_);
        
        for (int i = 0; i < n; i++) {
            cv_.wait(lk, [this] {return foo_turn; });        
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            
            foo_turn = false;
            cv_.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        unique_lock<mutex>  lk(mutex_);
        
        for (int i = 0; i < n; i++) {
            cv_.wait(lk, [this] {return !foo_turn; });
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();

            foo_turn = true;
            cv_.notify_all();
        }
    }
};