/*
ֱ������ n ����(���е�����x) ��ͬһֱ���� m ����(�绰��������x)�����е绰���Ĺ�����ʽ��һ����
����Ϊ���г����ṩ�绰�źţ���Щ������绰���ľ��벻���� r ������������ҳ�ÿ�����ж����źŵ���С r ��
��ÿ������������һ���绰��������벻���� r��
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+100; // 10^5+100 = 100000+100 = 100100
int n,m,a[N],b[N]; // n���������꣬m���绰������, a[100100]�����������飬b[100100]�绰����������
bool check(int x) {
	for (int i = 1; i <= n; i++) {
		int R=upper_bound(b + 1, b + m + 1, a[i] + x) - b; // ��b���ҵ���һ������a[i]+x��Ԫ�ص�����
		int L=lower_bound(b + 1, b + m + 1, a[i] - x) - b; // ��b���ҵ���һ��С�ڵ���a[i]-x��Ԫ�ص�����
		if(R-L<=0) // �绰���ķ�Χ��û�г���
            return false;
	}
	return true;
}
void solve() {
	cin>>n>>m;
	for(int i=1; i<=n; i++)cin>>a[i]; // ���������������
	for(int i=1; i<=m; i++)cin>>b[i]; // ����绰����������
    sort(a+1,a+1+n); // ������1��ʼ����a[0]δʹ��
	sort(b+1,b+1+m); // ������1��ʼ����b[0]δʹ��
	int l=0;
	int r=1e10;
	while(l<=r) { // ���ֲ���
		int mid=(l+r)>>1;
		if(check(mid))
            r=mid;
		else 
            l=mid+1;
	}
	cout<<r<<endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
