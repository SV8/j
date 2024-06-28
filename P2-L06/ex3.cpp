#include <iostream>
using namespace std;

int main() {
	
	int n, m;
	cin >> n >> m;
	int a[n][m];
	int b[m][n];
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> a[i][j];
		}
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			b[j][n-1-i] = a[i][j]; // 0,2 = 0,0 | 1,2 = 0,1 
		}
	}
	
	cout << endl;
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
}
