#include<bits/stdc++.h>
using namespace std;
char b[18] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
void st(int a){
	if(a / 16 != 0){
    	st(a / 16);
    }
    cout << b[a % 16];
}
int main(){
    int a;
    cin >> a;
    st(a);
    cout << endl;
	return 0;
}
