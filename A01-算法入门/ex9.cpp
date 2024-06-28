#include <iostream>
using namespace std;


int main() {
	
	int number;
	cin >> number;
	int save = number;
	char s[100];
	
	// binary
	char r;
	int p = 0;
	while(number!=0) {
		r = number%2;
		number/=2;
		s[p++] = r+48;
	}
	for(int i=p-1; i>=0; i--) {
		cout << s[i];
	}
	cout << " ";
	
	// oct
	r = 0;
	p = 0;
	number = save;
	while(number!=0) {
		r = number%8;
		number/=8;
		s[p++] = r+48;
	}
	for(int i=p-1; i>=0; i--) {
		cout << s[i];
	}
	cout << " ";
	
	// hex
	r = 0;
	p = 0;
	number = save;
	while(number!=0) {
		r = number%16;
		number/=16;
		if(r<=10)
			s[p++] = r+48;
		else
			s[p++] = r+55;
	}
	for(int i=p-1; i>=0; i--) {
		cout << s[i];
	}
	cout << endl;
	
	return 0;
}
