#include<iostream>
#include<cstdio>
using namespace std;

int f[1010];
int n;
int main() {
	for(int i=1; i<1010; i++) {
		f[i]=0;
	}
	scanf("%d", &n);
	f[1] = f[0] = 1;
	f[2] = 2;
	for(int i = 3; i <= n; ++i) {
		f[i] = f[i - 1];
		for(int j = 0; j <= i - 2; ++j) {
			f[i] += f[j] * f[i - 2 - j];
			f[i] %= 12345;
		}
	}
	printf("%d\n", f[n]);
	return 0;
}

