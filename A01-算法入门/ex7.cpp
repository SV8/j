#include <iostream>
using namespace std;

int main() {
	
	int len, n;
	cin >> len >> n;
	int s[len];
	int u, v;
	
	for(int i=0; i<len; i++) {
		cin >> s[i];
	}
	
	int temp;
	for(int j=0; j<n; j++) {
		cin >> u >> v;
		temp = s[u-1];
		s[u-1] = s[v-1];
		s[v-1] = temp;
		for(int k=0; k<len; k++) {
			cout << s[k] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
