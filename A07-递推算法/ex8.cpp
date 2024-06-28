#include <iostream>

using namespace std;

int paidui(int n) {

    long long d[31] = {0};

    // ��ʼ��
    d[0] = 1; // �շ����������� 1 
    d[1] = 1; // 1��ѧ����ֻ����M�������� 1
    d[2] = 2; // 2��ѧ����MM,FF�������� 2
    d[3] = 4; // 3��ѧ����MMM,FFF,MFF,FFM�������� 4 
    d[4] = 7; // 4��ѧ����MMMM,FFFF,MMFF,FFMM,MFFM,MFFF,FFFM�������� 7 
 
 	/* n>4
	�����i����M��ǰ���i-1����ֻҪ�Ϸ����м��ɣ�����������d[i-1]
	�����i����F����i-1��������F��ǰ���i-2���������������
		1)ֻҪ�Ϸ����м��ɣ���������d[i-2]
		2)��i-2��F,��i-3��M����������d[i-4] 
	����������n>4ʱ���ƹ�ʽΪ d[i] = d[i-1] + d[i-2] + d[i-4]
	*/
    for (int i = 5; i <= n; ++i) {
        d[i] = d[i-1] + d[i-2] + d[i-4];
    }

    return d[n];
}

int main() {
    int n;
    cin >> n;
    cout << paidui(n) << endl;
    return 0;
}
