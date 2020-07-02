#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

vector<int> getNexts(const string &s) {
	vector<int> nexts(s.size(), 0);

	for (size_t i = 1; i < s.size(); ++i) {
		int t = nexts[i-1];

		while (t > 0 && s[t] != s[i])
			t = nexts[t-1];
		if (s[t] == s[i])
			++t;
		nexts[i] = t;
	}
	return nexts;
}

int kmpMatch(const string &s, const string &p) {
	int i = 0, j = 0;
	auto nexts = getNexts(p);

	while (i < s.size() && j < p.size()) {
		if (s[i] == p[j]) {
			++j;
		} else {
			j = nexts[j];
		}
		++i;
	}

	if (j == p.size()) return i - p.size();
	return -1;
}

int main() {
	string s = "abcdcdcddd";
	string p = "dcd";

	int pos = kmpMatch(s, p);
	
	printf("s: %s\n", s.c_str());
	printf("p: %s\n", p.c_str());
	printf("pos: %d\n", pos);
}
