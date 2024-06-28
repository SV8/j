#include <bits/stdc++.h>

using namespace std;
const int N=500;
int m,n,a[N][N];
int main() {
	cin>>m>>n;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	string res;
	for (int i = 0; i < m + n - 1; i++) {
		if (i % 2) {
			int x = i < n ? 0 : i - n + 1;
			int y = i < n ? i : n - 1;
			while (x < m && y >= 0) {
				res+=to_string(a[x][y]);
				x++;
				y--;
			}
		} else {
			int x = i < m ? i : m - 1;
			int y = i < m ? 0 : i - m + 1;
			while (x >= 0 && y < n) {
				res+=to_string(a[x][y]);
				x--;
				y++;
			}
		}
	}
	cout<< res;
	return 0;
}
