#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		string res;
		vector<int> vec(num1.size()+num2.size(), 0);

		for (int i=0; i<num1.size(); ++i)
			for (int j=0; j<num2.size(); ++j) {
				vec[i+j] += (num1[num1.size()-1-i]-'0') * (num2[num2.size()-1-j]-'0');
			}
		
		int carry = 0;
		for (int &curr: vec) {
			curr += carry;
			carry = curr / 10;
			curr %= 10;
		}

		int i = vec.size()-1;
		while (i>0 && vec[i]==0) --i;

		for (; i>=0; --i) res += to_string(vec[i]);

		return res;
	}
};

int main(){
	string num1, num2, res;
	cin>>num1>>num2;

	Solution solu;
	res = solu.multiply(num1, num2);
	
	cout<<res<<endl;
}
