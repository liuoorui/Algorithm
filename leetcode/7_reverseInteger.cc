#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res = 0, rem;

        while (x) {
            rem = x % 10;
            x /= 10;
            if (abs(res)>INT_MAX/10 || 
                (abs(res)==INT_MAX/10 && (rem<-8 || rem>7))) 
                return 0;
            
            res = res * 10 + rem;
        }

        return res;
    }
};

int main() {
    int x, reversed_x;
    Solution solu;
    cout<<"input a 32-bit integer: ";
    cin>>x;

    reversed_x = solu.reverse(x);
    
    cout<<reversed_x<<endl;
}