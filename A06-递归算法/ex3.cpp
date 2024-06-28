//阅读以下程序并回答问题

#include<bits/stdc++.h>
using namespace std;
int n,a[1010];
int f(int x){
	if(a[x]!= -1) return a[x];
	int ans=1;
	for(int i=1;i<=x/2.0;i++){
		ans+=f(i);
	}
	return a[x]=ans;
}
int main(){
	cin>>n;
	memset(a,-1,sizeof(a));
	a[1]=1;
	f(n);
	cout<<a[n];
	return 0;
}

/*
n = 1, cout 1 f(1)=1
n = 2, cout 2 f(2)=2
n = 3, cout 2 f(3)=2
n = 4, cout 4 f(4)=4
n = 5, cout 4 f(5)=4
n = 6, cout 6 f(6)=6
...
*/
