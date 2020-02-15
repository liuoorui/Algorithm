#include <iostream>
#include <vector>
using std::cout;
using std::endl;

template <typename T>
class SharedPtr {
public:
    SharedPtr(T* ptr) 
    : ptr_(ptr), ref_count_(new int(1)) {
        cout << "A SP point to " << ptr_ << endl;
    }

    SharedPtr(const SharedPtr<T>& other) 
    : ptr_(other.ptr_), ref_count_(&(++(*other.ref_count_))) {
        cout << "A new SP point to " << ptr_ << endl;
    }

    const SharedPtr<T>& operator=(const SharedPtr<T>& rhs) {
        if (this == &rhs)
            return rhs;

        cout << "A new SP point to " <<  ptr_ << endl;
        if (ptr_ && --(*ref_count_) == 0) {
            delete ptr_;
            delete ref_count_;
            cout << ptr_ << " deleted by operator=" << endl;
        }

        ptr_ = rhs.ptr_;
        ref_count_ = &(++(*rhs.ref_count_));
        return *this;
    }

    ~SharedPtr() {
        cout << "~SharedPtr()" << endl;
        if (0 == --(*ref_count_)) {
            delete ptr_;
            delete ref_count_;
            cout << ptr_ << " deleted by ~SharedPtr()" << endl;
        }
    }

    T* get() const { return ptr_; }

    int getRef() const { return *ref_count_; }

    T* operator->() const { return ptr_; }

    T& operator*() { return *ptr_; }public:
    T* ptr_;
    int* ref_count_;
};

int main() {
    SharedPtr<double> ptr_a(new double(2));
    SharedPtr<double> ptr_b(ptr_a);
    SharedPtr<double> ptr_c(new double(3));

    ptr_a = ptr_b;
    ptr_c = ptr_a;

    cout << ptr_a.getRef() << " == " << ptr_b.getRef() << endl;
    
}