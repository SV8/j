#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	// 先把 n 的每一位反过来写，得到一个新的数 rn (例如：12345 -> 54321)
	int rn = 0, s = n;
	while(s!=0) {
		rn = rn*10 + s%10;
		s/=10;
	}
	
	// 如果rn等于n，n就是回文数
	if (rn == n) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}
