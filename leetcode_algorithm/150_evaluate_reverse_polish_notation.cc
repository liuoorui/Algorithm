#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty()) return 0;
        stack<int> s;
        
        for (auto token: tokens) {
            if (isdigit(token.back())) {
                s.push(atoi(token.c_str()));
                continue;
            }
            
            int left, right = s.top(), ans;
            s.pop();
            left = s.top();
            s.pop();
            
            switch (token[0]) {
                case '+': ans = left + right; break;
                case '-': ans = left - right; break;
                case '*': ans = left * right; break;
                case '/': ans = left / right; break;
            }
            s.push(ans);
        }
        
        return s.top();
    }
};