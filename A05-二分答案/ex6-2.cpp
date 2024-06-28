#include <iostream>
#include <algorithm>
using namespace std;

// ����С���Ϊ d ʱ���ж��ܷ�ŵ��� c ͷţ 
bool canPlaceCows(int h[], int n, int c, int d){
	int count = 1; // �ȷŵ�һͷ 
	int before = 0; // ��¼��һͷ���õ�λ��
	for(int i=1; i<n; i++) {
		if(h[i]-h[before] > d) { // ��ǰţ��Ų��£�����������һ��ţ��
			continue; 
		} else {
			count++; // �ɹ�����һͷţ
			before = i;
		}
	}
	if(count == c) // ����ţ��������� 
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
		if(canPlaceCows(house, N, C, mid)) { // �þ���ŵ��£���������Ը���ļ�� 
			left = mid + 1;
		} else { // �þ���Ų��£��������Ը�С�ļ�� 
			right = mid - 1; 
		}
	}
	int ans = mid; // �����������õ����ļ�� 
	cout << ans << endl;
}
