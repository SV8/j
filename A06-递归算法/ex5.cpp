/*
对于给定的一个长度为 N 的正整数数列 A，现要将其分成 M（M≤N）段，并要求每段连续，且每段和的最大值最小。
*/

#include <bits/stdc++.h>
using namespace std;

bool check(int a[], int n, int m, int mid) {
	int num = 0, total = 0;
	for(int i=0; i<n; i++) {
		if(total + a[i] > mid) { // exceed limit, start a new segment
			total = 0;
			num++; // increment the number of segments
		}
		total += a[i];
			
		if(num >= m)
			return true;
		return false; // unable to place enough segments using mid as the limit (mid is too big)
	}
} 

int main() {
	int n, m;
	cin >> n >> m;
	int a[n];
	int l=0, r=0;
	
	// l is the min of a[i] & r is accumulated sum of a[i]
	for(int i=0; i<n; i++) {
		cin >> a[i];
		l = min(l, a[i]);
		r = r + a[i];
	}
	
	// binary search
	int mid = 0;
	while(l<=r) {
		mid = (l+r)/2;
		if(check(a, n, m, mid)) {
			r = mid - 1; // try smaller half
		} else
			l = mid + 1; // try bigger half
	}
	
	cout << mid << endl;
	 
	return 0;
} 
