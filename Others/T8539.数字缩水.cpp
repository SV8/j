#include <iostream>
#include <string>
using namespace std;

int main() {
	
	string s;
	cin >> s;
	
	while (s.size() > 1 ) { // ֻʣһ���ַ�ʱ������ѭ��
		int index;
		// �������� 
		for(int i=0; i<s.size(); i++) {
			// Ҫ�����������ڵ�����С��û�ҵ���ѡ��ĩβ�Ǹ�
			if(s[i] < s[i+1] || i == s.size()-1) { 
				index = i;
				break;
			}
		}
		// ɾ�����֣�����string��erase������ 
		s.erase(index, 1);
		// ��ӡ���ֽ�� 
		cout << s << endl;
	}
}
