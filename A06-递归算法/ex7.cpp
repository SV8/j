//#include <bits/stdc++.h>
//using namespace std;
//
//char b[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
//
///* non-recursive  */
////int main() {
////	int n;
////	cin >> n;
////	int m = 0;
////	do {
////		int r = n%16;
////		s[m] = b[n%16];
////		n/=16;
////		m++;
////	} while(n!=0);
////	
////	for(int i=m-1; i>=0; i--)
////		cout << s[i];
////}
//
///*
//100
//6,4
//b[6], b[4]
//
//*/
//
///* recursive */
//void toHex(int n) {
//	if(n<16) {
//		cout << b[n];
//		return;
//	}
//	toHex(n/16); // higher digit 
//	cout << b[n%16]; // print current digit 
//}
//
//int main() {
//	int n;
//	cin >> n;
//	toHex(n);
//	return 0;
//}

#include<bits/stdc++.h>
using namespace std;
char b[18] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
void st(int a, int m){
	if(a / m != 0){
    	st(a / m, m);
    }
    cout << b[a % m];
}
int main(){
    int a, m;
    cin >> a >> m;
    st(a, m);
    cout << endl;
	return 0;
}
