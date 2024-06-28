#include <iostream>
using namespace std;

int main() {
	int line = 8 * 60 + 0;
	
	int hour, min;
	cin >> hour >> min;
	int a = (hour * 60) + min;
	
	if (a <= line) {
		cout << "on time" << endl;
	} else {
		cout << "late" <<endl;
	}
	
	return 0;
}
