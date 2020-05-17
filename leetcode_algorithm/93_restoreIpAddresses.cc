#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> strRes;
		vector<vector<int>> res;
		vector<int> curr;

		solve(res, s, curr, 0);

		for (auto nums: res) {
			string str = "";
			for (int num: nums)
				str += to_string(num) + ".";
			str.pop_back();

			strRes.push_back(str);
		}

		return strRes;
	}
private:
	void solve(vector<vector<int>>& res, string& s, vector<int> &curr, int pos) {
		if (curr.size() == 4) {
			if (pos == s.size()) res.push_back(curr);
			return;
		}

		for (int i=1; i<=3 && pos+i<=s.size(); ++i) {
			int num = atoi(s.substr(pos, i).c_str());

			if (num < 256) {
				curr.push_back(num);
				solve(res, s, curr, pos+i);
				curr.pop_back();
			}

			if (num == 0) break;
		}
	}
};

int main() {
	string s;
	vector<string> res;

	cin>>s;
	Solution solu;
	res = solu.restoreIpAddresses(s);

	for (string str: res)
		cout<<str<<endl;
}
