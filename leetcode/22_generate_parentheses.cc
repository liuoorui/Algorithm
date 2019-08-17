#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;

        dfs(res, n, "", 0, 0);

        return res;
    }
private:
    void dfs(vector<string>& res, int n, 
            string curr, int left, int right) {
        if (left<right || left>n || right>n) return;
        if (left+right == 2*n) {
            res.push_back(curr);
            return;
        }

        dfs(res, n, curr+'(', left+1, right);
        dfs(res, n, curr+')', left, right+1);
    }
};

int main() {
    Solution solu;
    vector<string> res;
    int n;

    cout<<"Input n: ";
    cin>>n;

    res = solu.generateParenthesis(n);

    for (string str: res)
        cout<<"\""<<str<<"\" ";
    cout<<endl;
}