#include <iostream>
using namespace std;

int main() {
	int a, b, n;
	cin >> n >> a >> b;
	int apples[n] = {}; // 全部初始化为0
	
	for(int i=0; i<n; i++) {
		cin >> apples[i];
	}
	
	for(int i=0; i<n; i++) {
		if(apples[i] <= b && apples[i] >= a) {
			cout << apples[i];
			cout << " ";
		}
	}
}
