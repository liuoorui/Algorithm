#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> vec;
        string ans = "";
        string::iterator i = path.begin(), j = path.begin();
        
        while (i < path.end()) {
            string str = "";
            while (j<path.end() && *j=='/') ++j;
            if (j == path.end()) break;
            i = j;
            j = find(i, path.end(), '/');
            str = string(i, j);
            
            i = j;
            if (str == "..") {
                if (!vec.empty()) vec.pop_back();
            } else if (str != ".") {
                vec.push_back(str);
            }
        }
        
        for (string str: vec) ans += "/" + str;
        if (ans.empty()) ans = "/";
        return ans;
    }
};