#include <iostream>
#include <mutex>
#include <conditon_variable>
#include <thread>

class H2O {
public:
    H2O() {
        num_o_ = 1;
        num_h_ = 2;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex>  ulk(mtx_);

        cv_.wait(ulk, [this] { return num_h_ > 0; });
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        --num_h_;
        if (num_h_ == 0 && num_o_ == 0) {
            num_o_ = 1;
            num_h_ = 2;
        }
        cv_.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex>  ulk(mtx_);

        cv_.wait(ulk, [this] { return num_o_ > 0; });
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        --num_o_;
        if (num_h_ == 0 && num_o_ == 0) {
            num_o_ = 1;
            num_h_ = 2;
        }
        cv_.notify_all();
    }

private:
    mutex   mtx_;
    int     num_o_;
    int     num_h_;
    condition_variable  cv_;
};