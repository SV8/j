#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

// Implementation of the user-defined binary function.
bool comp(int element1, int element2){
    // Returning the smaller value.
    return (element1 > element2);    
}

int main() {
	//char a[] = "AC3456\0xiaomawang";
	//cout << strlen(a) << endl;
	//char *a = "I am a student.";
	//cin >> a;
	//cout << a;
	cout << max(5, 10) << endl;
	cout << max(10, 5) << endl;
	cout << std::max(5, 10, comp) << endl;
	
}
