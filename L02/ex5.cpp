#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int number;
	int d0, d1, d2;
	
	cin >> number;
	
	d0 = number % 10;
	d1 = (number / 10) % 10;
	d2 = (number / 100) % 10;
	
	printf("%d%d%d", d0, d1, d2);
}
