#include <iostream>
using namespace std;

int main() {
	int t;	// ���������������
	int n;	// ��ǰ��һ�У��������ٸ����� 
	int k;	// ��ǰ����������������С�ͣ���kֵ 
	int sum = 0;	// ����õ�����С��
	int sumt = 0;	// �����м���
	int result[t];	// ����ÿһ�е�kֵ����ӡ������鼴�� 
	 
	cin >> t; 
	
	for(int i=0; i<t; i++) {
		
		cin >> n;	// ���������ĸ��� 
		int numbers[n];	// ����numbers��������һ�е����� 
		
		//sum = 0;	// ��ǰ�е���С�ͳ�ʼ��Ϊ0 
		
		// �������
		for (int j=0; j<n; j++) {
			cin >> numbers[j];
		}
		
		// k�ķ�Χ��1~30000������ÿ��kֵ��Ӧ�ĺͣ���׷����С�ĺ� 
		for (int kt=1; kt<30000; kt++) {
			sumt = 0;
			for(int j=0; j<n; j++) {
				if (kt - numbers[j] >= 0)
					sumt += kt - numbers[j];
				else
					sumt += numbers[j] - kt;
			}
			
			// �Ƚϴ�С 
			if(kt == 1) {
				sum = sumt;
				k = kt;
			} else {
				if(sumt < sum) {
					sum = sumt;
					k = kt;
				}
			}
		}
		
		// ������浽result���� 
		result[i] = sum;
	}
	
	// ��ӡ���ս�� 
	for(int i=0; i<t; i++)
		cout << result[i] << endl;
	
	return 0;
}
