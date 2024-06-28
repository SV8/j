#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	int n,n2,b,l,m,r,ans;
    cin >> n;
    for(int i = 0;i < n;i ++){
    	cin >> a[i];
    }
    sort(a,a + n);
    cin >> n2;
    for(int i = 0;i < n2;i ++){
    	cin >> b;
        l = 1;
        r = n;
        m = (l + r) / 2;
        ans = m;
        while(a[m - 1] != b){
            if(a[m - 1] > b){
            	r = m - 1;
            } else {
            	l = m + 1;
                ans = r;
            }
        	m = (l + r) / 2;
        }
        cout << ans << endl;
    }
	return 0;
}
