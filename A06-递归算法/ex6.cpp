#include <bits/stdc++.h>
using namespace std;

int find(int a, int b, int c) {
	if(a%b==0)
		return a;
	else
		find(a+c, b, c);
}

int main() {
	int n, m;
	cin >> n >> m;
	int result = find(n, m, n);
	cout << result << endl;
}
