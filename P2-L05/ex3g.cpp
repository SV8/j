#include<iostream>
using namespace std;
int main(){
	
	int a = 0;	// ���� 
	int n = 0;	// ��ǰ�е��������� 
	int c = 0;	// �����м��� 
	int k;		// ��ǰ����С�Ͷ�Ӧ��kֵ 
	int cn;		// ��ǰ����С�� 
	int u;		// ����ֵ�м��� 
	
	cin >> a;
	int p[a];	// ����p����ÿһ�е�kֵ������ӡ�������� 
	
	for(int i = 0;i < a;i += 1){
		cin >> n;
		int b[n];	// ��ǰ�е����ֱ��浽����b 
		
		for(int j = 0;j < n;j += 1){
			cin >> b[j];
		}
		for(int j = 0;j < 30000;j += 1){
			//cn = c;
			c = 0;
			k = j;
			for(int l = 0;l < n;l += 1){
				if(k - b[l] < 0){
					u = (k - b[l]) * -1;
				} else {
					u = k - b[l];
				}
				c += u;
			}
			if(j == 0){
				p[i] = c;
			} else {
				if(c < cn){
					p[i] = c;
				}	
			}
		}
	}
	for(int i = 0;i < a;i ++){
		cout << p[i] << endl;
	}
	return 0;
}
