#include <iostream>
using namespace std;

void simpleStringMatch(char* T, char* P, int* res) {
	int N = strlen(T), M = strlen(P);
	int i = 0;

	while (i <= N-M) {
		int j = 0;
		while (j<M && T[i+j]==P[j]) ++j;
		if (j==M) {
			*res = i;
			++res;
		}

		++i;
	}
}

int main(){
	int res[10];
	char str[256], pat[256];
	
	cout<<"input the str: "<<endl;
	cin>>str;
	cout<<"input the patten str: "<<endl;
	cin>>pat;

	simpleStringMatch(str, pat, res);

	for (int i=0; i<10; ++i)
		cout<<res[i]<<" ";
	cout<<endl;
}
