#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	// �Ȱ� n ��ÿһλ������д���õ�һ���µ��� rn (���磺12345 -> 54321)
	int rn = 0, s = n;
	while(s!=0) {
		rn = rn*10 + s%10;
		s/=10;
	}
	
	// ���rn����n��n���ǻ�����
	if (rn == n) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}
