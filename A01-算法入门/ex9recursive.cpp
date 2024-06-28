#include <iostream>
using namespace std;

// µ›πÈ–¥∑® 

void show_digit(int n, int t) {
	int r = 0;
	if(n!=0) {
		r = n%t;
		n /= t;
		show_digit(n, t);
		if(r<10) 
			cout << r;
		else
			cout << char(r+55);
	}
}

int main() {
	
	int number;
	cin >> number;
	
	// binary
	show_digit(number, 2);
	cout << endl;
	
	// oct
	show_digit(number, 8);
	cout << endl;
	
	// hex
	show_digit(number, 16);
	
	return 0;
}
