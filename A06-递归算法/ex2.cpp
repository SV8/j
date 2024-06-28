#include<bits/stdc++.h>
using namespace std;
long long f1(int n){
	if(n<=2){
		return n;
	}else{
		return f1(n-1)+f1(n-2);
	}
}
long long f2(int n){
	long long a[2005];
	a[1]=1;
	a[2]=2;
	for(int i=3;i<=n;i++){
		a[i]=a[i-1]+a[i-2];
	}
	return a[n];
}
int main(){
	int n;
	cin>>n;
	cout<<f1(n)<<endl;
	cout<<f2(n)<<endl;
	return 0;
}


// f1(2000) = f1(1999) + f1(1998) = f1(1998) + f1(1997) + f1(1997) + f1(1996) = f1(1997) + f1(1996) + f1(1996) + f1(1995) + f1(1996) + f1(1995) + f1(1995) + f1(1994) 
