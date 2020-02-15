#include <iostream>
#include <pthread.h>
using namespace std;

template<typename T>
class Singleton {
public:
    static T& instance() {
        pthread_once(&ponce_, &Singleton::init);
        return *value_;
    }
private:
    Singleton() {}
    ~Singleton() {}

    static void init() {
        value_ = new T();
    }

private:
    static pthread_once_t ponce_;
    static T* value_;
};

template<typename T>
pthread_once_t Singleton<T>::ponce_ = PTHREAD_ONCE_INIT;

template<typename T>
T* Singleton<T>::value_ = nullptr;

int main() {
    int& n = Singleton<int>::instance();
    int& n2 = Singleton<int>::instance();
    std::cout << "&n: " << &n << std::endl;
    std::cout << "&n2: " << &n2 << std::endl;
}
