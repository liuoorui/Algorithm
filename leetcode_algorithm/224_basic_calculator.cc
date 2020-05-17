class Solution {
public:
    int calculate(string s) {
        if (s.empty()) return 0;
        stack<int> nums;
        stack<char> ops;
        int beg = 0, end = 0;
        
        while (beg < s.size()) {
            if (isdigit(s[beg])) {
                end = beg;
                while (end < s.size() && isdigit(s[end])) ++end;
                
                int num = stoi(s.substr(beg, end - beg));
                if (!ops.empty()) {
                    char op = ops.top();
                    if (op != '(') {
                        int lhs = nums.top();
                        nums.pop();
                        ops.pop();
                        if (op == '+') num = lhs + num;
                        else if (op == '-') num = lhs - num;
                    }
                }
                nums.push(num);
                beg = end;
            } else {
                char op = s[beg];
                
                if (op == ')') {
                    ops.pop();
                    if (!ops.empty() && ops.top() != '(') {
                        int rhs = nums.top();
                        int op = ops.top();
                        nums.pop();
                        ops.pop();
                        
                        if (op == '+') nums.top() += rhs;
                        else if (op == '-') nums.top() -= rhs;
                    }
                }
                else if (op != ' ') ops.push(op); // '+', '-', '('.
                ++beg;
            }
        }
        
        return nums.top();
    }
};
