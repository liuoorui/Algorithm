#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == -1) return 1 / x;
        
        double f = myPow(x, n/2);
        // 注意这里不能写成 myPow(f, 2), 否则会死循环；
        return f * f * myPow(x, n-n/2*2);
    }
};

int main() {
    Solution solu;
    int x, n, res;

    cout<<"Input x: ";
    cin>>x;
    cout<<"Input n: ";
    cin>>n;

    res = solu.myPow(x, n);

    cout<<"pow("<<x<<", "<<n<<") = "<<res<<endl;
}