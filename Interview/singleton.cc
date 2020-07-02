#include <stdio.h>
using namespace std;

// 饱汉
class Singleton {
public:
	Singleton* instance() {
		if (singleton == nullptr) {
			pthread_mutex_lock(&mutex);
			if (singleton == nullptr)
				singleton = new Singleton();
			pthread_mutex_unlock(&mutex);
		}

		return singleton;
	}
private:
	Singleton(){
		pthread_mutex_init(&mutex);
	};

	static Singleton *singleton;
	static pthread_mutex_t mutex;
};

Singleton *Singleton::singleton = nullptr;
pthread_mutex_t Singleton::mutex;


// 饿汉
class Singleton {
public:
	Singleton* instance() {
		return singleton;
	}
private:
	Singleton() {}
	static Singleton *singleton;
};

Singleton Singleton::singleton = new Singleton();


// pthread_once，参考陈硕
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
