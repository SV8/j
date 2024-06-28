/*
ÒÑÖª n e d
Î´Öª p q

n = p*q
e*d = p*q - p - q + 2

p*q = n
p+q = n-e*d+2

770 77 5
p*q = 770
p+q = 387

10
770 77 5
633 1 211
545 1 499
683 3 227
858 3 257
723 37 13
572 26 11
867 17 17
829 3 263
528 4 109

*/

#include <bits/stdc++.h> 
using namespace std;

int main() {
	int rows;
	cin >> rows;
	int r[rows][3];
	for(int i=0; i<rows; i++) cin >> r[i][0] >> r[i][1] >> r[i][2];
	
	for(int i=0; i<rows; i++) {
		bool f = false;
		int n = r[i][0];
		int e = r[i][1];
		int d = r[i][2];
		int m = n - e*d + 2;
		//cout << "p+q=" << n << ",p*q=" << m << endl;
		for(int p=1; p<m; p++) {
			int q = m - p;
			//cout << "p=" << p << ",q=" << q << endl;
			if(p*q == n) {
				cout << p << " " << q << endl;
				f = true;
				break;
			}
		}
		if(!f)
			cout << "NO" << endl;
	}
}
