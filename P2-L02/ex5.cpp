#include <iostream>
#include <cstring>
using namespace std;

int main() {
	string s, a, b;
	int n;
	int cmd;
	cin >> s >> n;
	for(int i=0; i<n; i++) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> a;
			s += a;
		} else if (cmd == 2) {
			cout << s.length() << endl;
		} else if (cmd == 3) {
			cin >> b;
			if (s > b)
				cout << s << endl;
			else
				cout << b << endl;
		}
	}
	
	return 0;
}
