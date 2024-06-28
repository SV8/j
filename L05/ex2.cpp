#include <iostream>
using namespace std;

int main() {
	int a, b, c;	//ÆëÍõµÄ3Æ¥Âí 
	int a1, b1, c1; //Ìï¼ÉµÄ3Æ¥Âí 
	cin >> a >> b >> c;
	cin >> a1 >> b1 >> c1;
	if ((a < a1 && b < b1) || (a < a1 && c < c1) || (b < b1 && c < c1)) {
		cout << "LOSE" << endl;	//Ìï¼ÉÊäÁË 
	} else {
		cout << "WIN" << endl;	//Ìï¼ÉÓ®ÁË 
	}
}
