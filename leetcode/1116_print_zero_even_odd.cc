#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

class ZeroEvenOdd {
private:
    int n;
    int idx_;
    bool    zero_turn_;
    bool    even_turn_;
    mutex   mtx_;
    condition_variable  cv_;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        idx_ = 0;
        zero_turn_ = true;
        even_turn_ = false;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        unique_lock<mutex>  ulk(mtx_);
        
        for (int i = 0; i < n; ++i) {
            cv_.wait(ulk, [this] { return zero_turn_; });
            
            printNumber(0);
            zero_turn_ = false;
            cv_.notify_all();
        }
        
        // 处理第n + 1个数字对应线程退出。
        cv_.wait(ulk, [this] { return zero_turn_; });
        zero_turn_ = false;
        cv_.notify_all();
    }

    void even(function<void(int)> printNumber) {
        unique_lock<mutex>  ulk(mtx_);
        
        while (true) {
            cv_.wait(ulk, [this] { return !zero_turn_ && even_turn_; });

            if (++idx_ <= n) {
                printNumber(idx_);
                zero_turn_ = true;
                even_turn_ = false;
                cv_.notify_all();
            } else {
                even_turn_ = false;
                cv_.notify_all();
                break;
            }
        }
    }

    void odd(function<void(int)> printNumber) {
        unique_lock<mutex>  ulk(mtx_);
        
        while (true) {
            cv_.wait(ulk, [this] { return !zero_turn_ && !even_turn_; });
            
            if (++idx_ <= n) {
                printNumber(idx_);
                zero_turn_ = true;
                even_turn_ = true;
                cv_.notify_all();
            } else {
                even_turn_ = true;
                cv_.notify_all();
                break;
            }
        }
    }
};