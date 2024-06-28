#include <iostream>
#include <cstring>
using namespace std;

int main() {
	double t = 0.0, r = 0.0;
	string s1, s2;
	cin >> t >> s1 >> s2;
	int count = 0;
	for(int i=0; i<s1.size(); i++) {
		if(s1[i] == s2[i]) {
			count++;
		}
	}
	r = count*1.0/s1.size();
	if (r >= t) {
		cout << "yes" << endl;
	} else {
		cout << "no" << endl;
	}
	return 0;
}
