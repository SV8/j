#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	
	int n, m;
	cin >> n >> m;
	int b[n]; // biscuits
	int c[m]; // children
	
	for(int i=0; i<n; i++)
		cin >> b[i];
	for(int i=0; i<m; i++)
		cin >> c[i];
	
	sort(b, b+n);
	sort(c, c+m);
	
	int t = 0;
	
//	for(int i=0; i<m; i++) {
//		for(int j=0; j<n; j++) {
//			if(b[j] >= c[i]) {
//				b[j] = 0;
//				t++;
//				break;
//			}
//		}
//	}

	int i = 0, j = 0;
	while(i<n && j<m) {
		if(b[i] >= c[j]) { 
			t++; // satisfied + 1
			j++; // next child
		}
		i++; // next biscuit
	}
	
	cout << t << endl;
	return 0;
}
