#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int n; //����
	int h; //���
	double t = 0; //��ʱ�����������ܵ����
	
	cin >> n; //���������� 
	
	for(int i=0; i<n; i+=1) {
		cin >> h; //��������һ���˵���� 
		t += h; //�ѽ���ۼӵ���ʱ���� 
	}
	printf("ƽ�����Ϊ: %.2f", t/n);
}
