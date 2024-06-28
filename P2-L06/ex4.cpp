#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	char a[n][m];
	char b[n][m];
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> a[i][j];
		}
	}
	
	cout << endl;
	
	for(int i=n-1; i>=0; i--) {
		for(int j=0; j<m; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
