#include <iostream>
using namespace std;

int main() {
	int a, b, c;	//������3ƥ�� 
	int a1, b1, c1; //��ɵ�3ƥ�� 
	cin >> a >> b >> c;
	cin >> a1 >> b1 >> c1;
	if ((a < a1 && b < b1) || (a < a1 && c < c1) || (b < b1 && c < c1)) {
		cout << "LOSE" << endl;	//������� 
	} else {
		cout << "WIN" << endl;	//���Ӯ�� 
	}
}
