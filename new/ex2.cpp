#include <iostream>
using namespace std;

int main() {
	
	int n;
	cin >> n;
	int matrix[n][n];
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			matrix[i][j] = 0;
		}
	}
	
	int last_i, last_j;
	int k = 0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			k++;
			//cout << "k = " << k << endl;
			if(k == 1) {
				//cout << "case 0" << endl;
				matrix[0][n/2] = k;
				last_i = 0;
				last_j = n/2;
			} else {
				if(last_i == 0 && last_j != n-1) {
					//cout << "case 1" << endl;
					matrix[n-1][last_j+1] = k;
					last_i = n-1;
					last_j = last_j+1;
				}
				else if(last_j == n-1 && last_i != 0) {
					//cout << "case 2" << endl;
					matrix[last_i-1][0] = k;
					last_i = last_i-1;
					last_j = 0;
				}
				else if(last_i == 0 && last_j == n-1) {
					//cout << "case 3" << endl;
					matrix[last_i+1][last_j] = k;
					last_i = last_i+1;
					last_j = last_j;
				}
				else if(last_i != 0 && last_j != n-1) {
					//cout << "case 4" << endl;
					if(matrix[last_i-1][last_j+1] == 0) {
						//cout << "case 4-1" << endl;
						matrix[last_i-1][last_j+1] = k;
						last_i = last_i-1;
						last_j = last_j+1;
					} else {
						//cout << "case 4-2" << endl;
						matrix[last_i+1][last_j] = k;
						last_i = last_i+1;
						last_j = last_j;
					}
				}
			}
			//cout << "matrix[" << last_i << "][" << last_j << "] = " << k << endl;
		}
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout << matrix[i][j];
		}
		cout << endl;
	}
	
	return 0;
}
