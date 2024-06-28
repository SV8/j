#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    char g[n][m];
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> g[i][j];
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(g[i][j] == '*')
                cout << g[i][j];
            else {
            	int sum = 0;
                
				// count * in 8 grids around
				if(i-1>=0 && g[i-1][j] == '*') 	sum += 1; //top
				if(i+1<n && g[i+1][j] == '*')	sum += 1; // bottom
				if(j-1>=0 && g[i][j-1] == '*')	sum += 1; // left
				if(j+1<m && g[i][j+1] == '*')	sum += 1; // right
				if(i-1>=0 && j-1>=0 && g[i-1][j-1] == '*')	sum += 1; // top-left
				if(i-1>=0 && j+1<m && g[i-1][j+1] == '*')	sum += 1; // top-right
				if(i+1<n && j-1>=0 && g[i+1][j-1] == '*')	sum += 1; // top-left
				if(i+1<n && j+1<m && g[i+1][j+1] == '*')	sum += 1; // top-right
				
                cout << sum;
            }
        }
        cout << endl;
    }
}
