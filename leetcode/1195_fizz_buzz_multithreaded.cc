class FizzBuzz {
private:
    int n;
    int curr;
    bool    fizz_;
    bool    buzz_;
    mutex   mtx_;
    condition_variable  cv_;
    
    inline void setFizzBuzz(int next) {
        fizz_ = !(next % 3);
        buzz_ = !(next % 5);
    }

public:
    FizzBuzz(int n) {
        this->n = n;
        fizz_ = false;
        buzz_ = false;
        curr = 1;
        cv_.notify_all();
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        unique_lock<mutex>  ulk(mtx_);
        
        while (true) {
            cv_.wait(ulk, [this] { return fizz_ && !buzz_ || curr > n; });
            if (curr > n)
                break;
            
            setFizzBuzz(curr + 1);
            printFizz();
            ++curr;
            
            cv_.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        unique_lock<mutex>  ulk(mtx_);
        
        while (true) {
            cv_.wait(ulk, [this] { return !fizz_ && buzz_ || curr > n; });
            if (curr > n)
                break;
            
            setFizzBuzz(curr + 1);
            printBuzz();
            ++curr;
            
            cv_.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        unique_lock<mutex>  ulk(mtx_);
        
        while (true) {
            cv_.wait(ulk, [this] { return fizz_ && buzz_ || curr > n; });
            if (curr > n)
                break;
            
            setFizzBuzz(curr + 1);
            printFizzBuzz();
            ++curr;
            
            cv_.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        unique_lock<mutex>  ulk(mtx_);
        
        while (true) {
            cv_.wait(ulk, [this] { return !fizz_ && !buzz_ || curr > n; });
            if (curr > n) 
                break;
            
            setFizzBuzz(curr + 1);
            printNumber(curr);
            ++curr;
            
            cv_.notify_all();
        }
    }
};