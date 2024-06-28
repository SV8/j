/*
直线上有 n 个点(城市的坐标x) ，同一直线有 m 个点(电话塔的坐标x)。所有电话塔的工作方式都一样，
它们为所有城市提供电话信号，这些城市与电话塔的距离不超过 r 。你的任务是找出每个城市都有信号的最小 r ，
即每个城市至少有一个电话塔，其距离不超过 r。
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+100; // 10^5+100 = 100000+100 = 100100
int n,m,a[N],b[N]; // n个城市坐标，m个电话塔坐标, a[100100]城市坐标数组，b[100100]电话塔坐标数组
bool check(int x) {
	for (int i = 1; i <= n; i++) {
		int R=upper_bound(b + 1, b + m + 1, a[i] + x) - b; // 在b中找到第一个大于a[i]+x的元素的索引
		int L=lower_bound(b + 1, b + m + 1, a[i] - x) - b; // 在b中找到第一个小于等于a[i]-x的元素的索引
		if(R-L<=0) // 电话塔的范围内没有城市
            return false;
	}
	return true;
}
void solve() {
	cin>>n>>m;
	for(int i=1; i<=n; i++)cin>>a[i]; // 读入城市坐标数据
	for(int i=1; i<=m; i++)cin>>b[i]; // 读入电话塔坐标数据
    sort(a+1,a+1+n); // 从索引1开始排序，a[0]未使用
	sort(b+1,b+1+m); // 从索引1开始排序，b[0]未使用
	int l=0;
	int r=1e10;
	while(l<=r) { // 二分查找
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
