#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        
        while (--n) res = generate(res);
        
        return res;
    }
private:
    string generate(string s) {
        string next = "";
        int i = 0, cnt = 0;
        char curr;

        while (i < s.size()) {
            curr = s[i];
            cnt = 0;
            while (i<s.size() && s[i]==curr) {
                ++i;
                ++cnt;
            }
            
            next += to_string(cnt) + curr;
        }
        
        return next;
    }
};

int main() {
    Solution solu;
    int n;
    string res;

    cout<<"Input n: "<<endl;
    cin>>n;

    res = solu.countAndSay(n);

    cout<<res<<endl;
}