#include <iostream>
using namespace std;

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	int numbers[n] = {};
	int count = 0;
	
	for(int i=0; i<n; i++) {
		cin >> numbers[i];
	}
	
	for(int i=0; i<n; i++) {
		if(numbers[i] >= a && numbers[i] <= b) {
			count += 1;
		}
	}
	cout << count << endl;
	
	for(int i=0; i<n; i++) {
		if(numbers[i] >= a && numbers[i] <= b) {
			cout << numbers[i];
			cout << " ";
		}
	}
	cout << endl;
	
	for(int i=0; i<n; i++) {
		if(numbers[i] < a || numbers[i] > b) {
			cout << numbers[i];
			cout << " ";
		}
	}
}
