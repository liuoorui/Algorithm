#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int max_length = 0, left = -1;
		int map[256];
		for (int i=0; i<256; ++i) map[i] = -1;

		for (int i=0; i<s.size(); ++i) {
			left = max(left, map[s[i]]);

			max_length = max(max_length, i-left);

			map[s[i]] = i;
		}

		return max_length;
	}
};

int main() {
	string s;
	Solution solu;
	char chs[256];
	int n, res;
	
	cout<<"input the length of string: ";
	cin>>n;
	cin.clear();
	cin.sync();
	cin.ignore();
	cout<<"input string: ";
	cin.getline(chs, 256);
	for (int i=0; i<n; ++i) s.push_back(chs[i]);

	res = solu.lengthOfLongestSubstring(s);

	cout<<res<<endl;
}