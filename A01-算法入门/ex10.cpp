#include <bits/stdc++.h>
using namespace std;

bool isIn(int i, int j, int n, int m) {
	if(i < 0 || i >= n || j <0 || j>= m ) return false;
	return true;
}

int main() {
	
	int n, m;
	cin >> n >> m;
	
	// ��ɢǰ��״̬src, ��ɢ���״̬target
	int src[n][m];
	int target[n][m];
	memset(src, 0, sizeof(src));
	memset(target, 0, sizeof(target));
	
	// t����ʼ��ɢ�㣬���Ϊ 1 
	int t;
	cin >> t;
	int r, c;
	for(int i=0; i<t; i++) {
		cin >> r >> c;
		src[r-1][c-1] = target[r-1][c-1] = 1;
	}
	
	// �� k ����ɢ 
	int k;
	cin >> k;
	
//	// ��ӡ��ʼ״̬ 
//	cout << "��ʼ״̬:" << endl;
//	for(int i=0; i<n; i++) {
//		for(int j=0; j<m; j++) {
//			cout << src[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << t << endl;
//	cout << endl;

	for(int min=0; min<k; min++) {
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(src[i][j] == 1) {
					if(isIn(i-1, j, n, m) && (target[i-1][j] == 0))		// �� 
						t += (target[i-1][j] = 1);
					if(isIn(i+1, j, n, m) && (target[i+1][j] == 0))		// �� 
						t += (target[i+1][j] = 1);
					if(isIn(i, j-1, n, m) && (target[i][j-1] == 0))		// �� 
						t += (target[i][j-1] = 1);
					if(isIn(i, j+1, n, m) && (target[i][j+1] == 0))		// �� 
						t += (target[i][j+1] = 1);
				}
			}
		}
		
//		// ��ӡÿһ������ɢ��� 
//		cout << "�� " << min+1 << "���Ӻ�:" << endl;
//		for(int i=0; i<n; i++) {
//			for(int j=0; j<m; j++) {
//				cout << target[i][j] << " ";
//			}
//			cout << endl;
//		}
//		cout << t << endl;
//		cout << endl;
		
		// ״̬���£�׼����һ����ɢ 
		memset(src, 0, sizeof(src));
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				src[i][j] = target[i][j];
			}
		}
	}
	
	cout << t << endl;
}
