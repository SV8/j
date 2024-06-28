#include <iostream>
using namespace std;

int main() {
	int n, m;
	int cnt = 0;
	cin >> n >> m;
	while(n!=0) {
		if(n%10 == m) {
			cnt += 1;
		}
		n/=10;
	}
	cout << cnt << endl;
}
