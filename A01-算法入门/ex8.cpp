#include <bits/stdc++.h>
using namespace std;

bool isIn(int i, int j, int n, int m) {
	if(i < 0 || i >= n || j <0 || j>= m ) return false;
	return true;
}

int main() {
	
	int n, m;
	cin >> n >> m;
	int s[n][m];
	int r[n][m];
	memset(r, 0, sizeof(r));
	
	int flag;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> flag;
			s[i][j] = flag;
		}
	}
	
//	cout << endl;
//	
//	for(int i=0; i<n; i++) {
//		for(int j=0; j<m; j++) {
//			cout << s[i][j] << " ";
//		}
//		cout << endl;
//	}
//	
//	cout << endl;
//	
//	for(int i=0; i<n; i++) {
//		for(int j=0; j<m; j++) {
//			cout << r[i][j] << " ";
//		}
//		cout << endl;
//	}
//	
//	cout << endl;
	
	int sum;
	for (int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			sum = 0;
			
			if(isIn(i-1, j-1, n, m)) sum+=s[i-1][j-1]; // ����
			if(isIn(i-1, j, n, m)) sum+=s[i-1][j];     // �� 
			if(isIn(i-1, j+1, n, m)) sum+=s[i-1][j+1]; // ���� 
			
			if(isIn(i, j-1, n, m)) sum+=s[i][j-1];     // �� 
			if(isIn(i, j+1, n, m)) sum+=s[i][j+1];     // �� 
			
			if(isIn(i+1, j-1, n, m)) sum+=s[i+1][j-1]; // ���� 
			if(isIn(i+1, j, n, m)) sum+=s[i+1][j];     // �� 
			if(isIn(i+1, j+1, n, m)) sum+=s[i+1][j+1]; // ���� 
			
			if(s[i][j] == 1)  // �е������9  
				r[i][j] = 9;
			else			  // �޵�������ܱ����� 
				r[i][j] = sum;
		} 
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cout << r[i][j] << " ";
		}
		cout << endl;
	}
		
	return 0;
}
