#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		string res = "";
		stack<string> s;
		int p = 0, end;

		while (p < path.size()) {
			while (p<path.size() && path[p]=='/') ++p;
			if (p == path.size()) break;

			end = p + 1;
			while (end<path.size() && path[end]!='/') ++end;
			string sub = path.substr(p, end-p);
		
			p = end + 1;
			if (sub == ".") continue;
			else if (sub == "..") {if (!s.empty()) s.pop();}
			else s.push(sub);
		}
		
		if (s.empty()) return "/";
		while (!s.empty()) {
			res = "/" + s.top() + res;
			s.pop();
		}

		return res;
	}
};

int main() {
	string path;
	char s[256];
	cin.get(s, 256);
	int i=0; 
	while (i<256 && s[i]!='\0')
		path += s[i++];

	string res;
	Solution solu;
	
	res = solu.simplifyPath(path);
	
	cout<<res<<endl;
}
