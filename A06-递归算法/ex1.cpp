#include<bits/stdc++.h>
using namespace std;
int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int leapyear(int year){
	return ((year%4==0&&year%100!=0)||year%400==0);
}
int main(){
	int year,month,day;
	cin>>year>>month>>day;
	int ans=0;
	for(int i=1;i<month;i++){
		if(i==2&&leapyear(year)){
			ans+=1;
		}
		ans+=days[i];
	}
	ans+=day;
	cout<<ans;
	return 0;
}
