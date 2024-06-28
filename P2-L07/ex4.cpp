#include <iostream>
#include <cmath>
using namespace std;

int main() {
	
	int n, m; // number of rows and coloumns
	cin >> n >> m;
	int p[n][m]; // pixel values
	int np[n][m]; // updated pixel values
	
	// input values for pixels
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> p[i][j];
		}
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(i!=0 && i!=n-1 && j!=0 && j!=m-1) { // pixels in edges
				np[i][j] = round((p[i-1][j] + p[i+1][j] + p[i][j-1] + p[i][j+1] + p[i][j]) / 5.0);
			} else {
				np[i][j] = p[i][j];
			}
		}
	}
	
	cout << endl;
	// output new values for pixels
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cout << np[i][j] << " ";
		}
		cout << endl;
	}
}
