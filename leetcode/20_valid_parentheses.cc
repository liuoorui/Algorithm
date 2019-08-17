#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> my_stack;

        for (char right: s) {
            if (!my_stack.empty()) {
                char left = my_stack.top();

                if (isValid(left, right)) {
                    my_stack.pop();
                    continue;
                }
            }

            my_stack.push(right);
        }

        return my_stack.empty();
    }
private:
    bool isValid(char left, char right) {
        if (left=='(' && right==')') return true;
        if (left=='[' && right==']') return true;
        if (left=='{' && right=='}') return true;

        return false;
    }
};

int main() {
    Solution solu;
    string s;

    cout<<"Input a string: ";
    cin>>s;
    
    cout<<solu.isValid(s)<<endl;
}