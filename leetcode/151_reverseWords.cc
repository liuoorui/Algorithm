#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	void reverseWords(string &s) {
		int p = 0;

		while (p < s.size()) {
			while (p<s.size() && s[p]==' ') {
				s.erase(p, 1);
			}

			int end = p + 1;
			while (end<s.size() && s[end]!=' ') ++end;
			reverse(s.begin()+p, s.begin()+end);

			p = end + 1;
		}

		reverse(s.begin(), s.end());
		p = 0;
		while (p<s.size() && s[p]==' ')
			s.erase(p, 1);
	}
};

int main() {
	int n;
	string s;

	cin>>n;
	char str[256];
	// 这里输入有一点问题，需要在同一行输入字符串；
	// 输入不太会，有空专门学一下；
	cin.get(str, n);
	for (int i=0; i<n; ++i) s += str[i];
	

	Solution solu;
	solu.reverseWords(s);

	cout<<s<<endl;
}
