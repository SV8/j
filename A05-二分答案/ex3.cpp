#include <bits/stdc++.h>
using namespace std;
int main() {
	long long apples;
	cin>>apples;
	long long left = 1, right = 100000, ans = 0;
	while (left <= right) {
		long long mid = (left + right) / 2;
		if (2 * mid * (mid + 1) * (mid * 2 + 1) >= apples) {
			ans = mid;
			right = mid - 1;
			cout << 2 * mid * (mid + 1) * (mid * 2 + 1) << " >= " << apples << endl;
			cout << "mid = " << mid << endl;
			cout << "left = " << left << endl;
			cout << "right = " << right << endl << endl;
		} else {
			left = mid + 1;
			cout << 2 * mid * (mid + 1) * (mid * 2 + 1) << " < " << apples << endl;
			cout << "mid = " << mid << endl;
			cout << "left = " << left << endl;
			cout << "right = " << right << endl << endl;
		}
	}
	cout << ans * 8;
	return 0;
}
