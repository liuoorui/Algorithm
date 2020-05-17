class DiningPhilosophers {
public:
    DiningPhilosophers() {
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
	    int left = philosopher;
        int right = (philosopher + 1) % 5;
        
        {
            lock_guard<mutex> lck(glock_);
            lock_[left].lock();
            lock_[right].lock();
        }
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
        
        lock_[left].unlock();
        lock_[right].unlock();
    }
    
private:
    mutex lock_[5];
    mutex glock_;
};
