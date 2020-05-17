#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>

class Foo {
public:
    Foo(): after_one(false), after_two(false) {
        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        after_one = true;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lk(mt_);
        cv.wait(lk, [this]{return after_one;});
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        after_two = true;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lk(mt_);
        cv.wait(lk, [this]{return after_two;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
private:
    mutex mt_;
    condition_variable cv;
    bool after_one, after_two;
};