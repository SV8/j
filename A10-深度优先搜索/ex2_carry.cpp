#include <iostream>
using namespace std;


int main() {
	long long ans = 0;
	long long n, k;
	cin >> n >> k;
	//cout << "cin done." << endl;
	
	long long power = k;
	while(power <= n) {
		//cout << "while in." << endl;
		cout << (n / power) << endl;
		ans += (n / power);
		//cout << ans << endl;
		power *= k;
	}
	
	cout << ans << endl;
}
