#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		int leng1 = s1.size(); 
		int leng2 = s2.size();
		if (leng1 > leng2) return false;
		if (leng1 == 0) return true;
		
		vector<int> m1(26, 0), m2(26, 0);
		for (int i=0; i<leng1; ++i) {
			m1[s1[i]-'a']++;
			m2[s2[i]-'a']++;
		}
		if (m1 == m2) return true;

		for (int i=leng1; i<leng2; ++i) {
			m2[s2[i-leng1]-'a']--;
			m2[s2[i]-'a']++;
			if (m1 == m2) return true;
		}

		return false;
	}
};

int main() {
	string s1, s2;
	cin>>s1>>s2;

	Solution solu;
	cout<<solu.checkInclusion(s1, s2)<<endl;
}
