#include <bits/stdc++.h>
using namespace std;

bool isIn(int i, int j, int n, int m) {
	if(i < 0 || i >= n || j <0 || j>= m ) return false;
	return true;
}

int main() {
	
	int n, m;
	cin >> n >> m;
	
	// 扩散前的状态src, 扩散后的状态target
	int src[n][m];
	int target[n][m];
	memset(src, 0, sizeof(src));
	memset(target, 0, sizeof(target));
	
	// t个初始扩散点，标记为 1 
	int t;
	cin >> t;
	int r, c;
	for(int i=0; i<t; i++) {
		cin >> r >> c;
		src[r-1][c-1] = target[r-1][c-1] = 1;
	}
	
	// 共 k 轮扩散 
	int k;
	cin >> k;
	
//	// 打印初始状态 
//	cout << "初始状态:" << endl;
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
					if(isIn(i-1, j, n, m) && (target[i-1][j] == 0))		// 上 
						t += (target[i-1][j] = 1);
					if(isIn(i+1, j, n, m) && (target[i+1][j] == 0))		// 下 
						t += (target[i+1][j] = 1);
					if(isIn(i, j-1, n, m) && (target[i][j-1] == 0))		// 左 
						t += (target[i][j-1] = 1);
					if(isIn(i, j+1, n, m) && (target[i][j+1] == 0))		// 右 
						t += (target[i][j+1] = 1);
				}
			}
		}
		
//		// 打印每一步的扩散结果 
//		cout << "第 " << min+1 << "分钟后:" << endl;
//		for(int i=0; i<n; i++) {
//			for(int j=0; j<m; j++) {
//				cout << target[i][j] << " ";
//			}
//			cout << endl;
//		}
//		cout << t << endl;
//		cout << endl;
		
		// 状态更新，准备下一轮扩散 
		memset(src, 0, sizeof(src));
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				src[i][j] = target[i][j];
			}
		}
	}
	
	cout << t << endl;
}
