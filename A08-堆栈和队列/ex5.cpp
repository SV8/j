#include <bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int n,h[N],L[N],R[N];
int main() {
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> h[i];
	}
	for(int i=0; i<n; i++) {
		L[i] = -1;
		R[i] = n;
	}
	stack<int> st;
	for (int i = 0; i < n; i++) {
		while (!st.empty() && h[i] <= h[st.top()]) {
			st.pop();
		}
		if (!st.empty()) {
			L[i] = st.top();
		}
		st.push(i);
	}
	st = stack<int>();
	for (int i = n - 1; i >= 0; i--) {
		while (!st.empty() && h[i] <= h[st.top()]) {
			st.pop();
		}
		if (!st.empty()) {
			R[i] = st.top();
		}
		st.push(i);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, h[i] * (R[i] - L[i] - 1));
	}
	cout << ans;
	return 0;
}
