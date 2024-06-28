#include <iostream>
#include <algorithm>
using namespace std;

// 当最小间距为 d 时，判断能否放得下 c 头牛 
bool canPlaceCows(int h[], int n, int c, int d){
	int count = 1; // 先放第一头 
	int before = 0; // 记录上一头放置的位置
	for(int i=1; i<n; i++) {
		if(h[i]-h[before] > d) { // 当前牛棚放不下，继续尝试下一个牛棚
			continue; 
		} else {
			count++; // 成功放置一头牛
			before = i;
		}
	}
	if(count == c) // 所有牛都放置完毕 
		return true;
	else
		return false; 
}

int main() {
	int N, C;
	int house[N];	
	cin >> N >> C;
	for(int i=0; i<N; i++)
		cin >> house[i];
	sort(house, house+N);
	
	// Binary search
	int left = 0, right = 1000000000;
	int mid = 0;
	while(left<=right) {
		mid = (left + right) / 2;
		if(canPlaceCows(house, N, C, mid)) { // 该距离放得下，则继续尝试更大的间距 
			left = mid + 1;
		} else { // 该距离放不下，继续尝试更小的间距 
			right = mid - 1; 
		}
	}
	int ans = mid; // 搜索结束，得到最大的间距 
	cout << ans << endl;
}
