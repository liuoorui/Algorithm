#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxAeraOfIsland(vector<vector<int> >& grid) {
		if (grid.empty() || grid[0].empty()) return 0;
		// 2表示标记过的1;
		int maxAera = 0;
		for (int i=0; i<grid.size(); ++i)
			for (int j=0; j<grid[i].size(); ++j) {
				if (grid[i][j]==0 || grid[i][j]==2) continue;
				
				int currAera = calcAera(grid, i, j);
				maxAera = max(maxAera, currAera);
			}

		return maxAera;
	}
private:
	int calcAera(vector<vector<int> >&grid, int i, int j) {
		if (i<0 || i==grid.size() || j<0 || j==grid[0].size()) return 0;
		if (grid[i][j]==0 || grid[i][j]==2) return 0;

		grid[i][j] = 2;
		return 1 + calcAera(grid, i-1, j) + calcAera(grid, i+1, j)
				+ calcAera(grid, i, j+1) + calcAera(grid, i, j-1);
	}
};

int main() {
	vector<vector<int> > grid;
	int m, n;
	cin>>m>>n;
	for (int i=0; i<m; ++i) {
		grid.push_back(vector<int>());
		for (int j=0; j<n; ++j) {
			int num;
			cin>>num;
			grid[i].push_back(num);
		}
	}

	Solution solu;
	int res = solu.maxAeraOfIsland(grid);
	cout<<res<<endl;
}
