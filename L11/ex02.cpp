#include <iostream>
using namespace std;

int main() {
	int a,b,c,d;
    cin >> a;
	b = a % 10;
    c = (a / 10) % 10;
    d = a / 100;
    if(d * d * d + b * b * b + c * c * c == a){
    	cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
	return 0;
}
