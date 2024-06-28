#include <iostream>
using namespace std;

int main() {
	int a, b, c = 0;
	cin >> a >> b;
	for(int i=1; i<=a*b; i++) {
		if(i%a==0 && i%b==0) {
			c = i;
			break;
		}
	}
	cout << c << endl;
}
