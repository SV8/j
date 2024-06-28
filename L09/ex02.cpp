#include<iostream>
using namespace std;
int main(){
    int l,z,s;
    cin >> l;
    int a[l];
    for(int i = 0;i < l;i++){
    	cin >> a[i];
    }
    z = a[l-1];
    for(int i = l - 1;i >= 0;i--){
    	if(a[i] > z){
        	z = a[i];
        }
    }
    cout << "max: " << z << endl;
    s = z;
    for(int i = l - 1;i >= 0;i--){
    	if(a[i] < s){
        	s = a[i];
        }
    }
    cout << "min: " << s << endl;
    cout << "sum: " << s + z << endl;
	return 0;
}
