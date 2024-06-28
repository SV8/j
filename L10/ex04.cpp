#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n] = {};
	
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	
	// 第一步，找到数组a中的最大值
	int max = a[0];
	for(int i=0; i<n; i++) {
		if(a[i] > max) {
			max = a[i];
		}
	}
	
	//cout << max << endl;
	
	// 第二步，判断max是否为质数
	bool flag = true;
	for(int i=2; i<max; i++) {
		if(max%i == 0) {
			flag = false;
			break;
		}
	}
	
	if(flag == false || max == 1) {
		cout << "False" << endl;
	} else {
		cout << max << " True" << endl;
	}
}
