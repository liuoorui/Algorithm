#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
using namespace std;

// 用两个线程交替打印 0 - 100 的奇偶数字。
class Printer {
public:
    Printer(int n)
    :   odd_(false), 
        end_(n),
        idx_(0) { 
            cout << "init..." << endl;
        }

    void start() {
        thread t1(&Printer::printOdd, this);
        thread t2(&Printer::printEven, this);

        t1.join();
        t2.join();
    }

    void printOdd() {
        unique_lock<mutex>  ulk(mtx_);
        cout << "thread odd start..." << endl;

        while (true) {
            cv_.wait(ulk, [this] { return odd_; });

            odd_ = false;
            if (idx_ <= end_) {
                cout << idx_++ << ", ";
                cv_.notify_all();
            } else {
                cv_.notify_all();
                break;
            }
        }
    }

    void printEven() {
        unique_lock<mutex>  ulk(mtx_);
        cout << "thread even start..." << endl;

        while (true) {
            cv_.wait(ulk, [this] { return !odd_; });

            odd_ = true;
            if (idx_ <= end_) {
                cout << idx_++ << ", ";
                cv_.notify_all();
            } else {
                cv_.notify_all();
                break;
            }
        }
    }
private:
    mutex   mtx_;
    bool    odd_;
    int     end_;
    int     idx_;
    condition_variable  cv_;
};

int main() {
    Printer printer(100);
    printer.start();
    cout << endl;

    // thread  t_odd(bind(&Printer::printOdd, &printer));
    // thread  t_even(bind(&Printer::printEven, &printer));
}