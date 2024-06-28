#include <iostream>
#include <stack>
//#include <bits/stdc++.h>
using namespace std;

int main() {
	int q;
	cin >> q;	// һ�� q ������ 
	int n[q];	// ÿ������г��� 
	stack<int> qstack[q];	// ÿ�����һ��stack 
	int pushed[q][100005];	// q����ջ����
	int poped[q][100005];	// q���ջ���� 
	
	// ���������������ݲ����� 
	for(int i=0; i<q; i++) {
		cin >> n[i];
		for(int j=0; j<n[i]; j++) {
			cin >> pushed[i][j];
		}
		for(int j=0; j<n[i]; j++) {
			cin >> poped[i][j];
		}
	}
	
	// ��ʼ��֤ 
	for(int i=0; i<q; i++) {
		int index = 0;	// ��ջ���е��±� 
		for(int j=0; j<n[i]; j++) {
			qstack[i].push(pushed[i][j]);	// ��ջ���е���һ��������ջ
			while(!qstack[i].empty() && (qstack[i].top() == poped[i][index])) {	// ��������ջ��������ִ�г�ջ���� 
				qstack[i].pop();	// ��ջ
				index++;	// ����ջ�����е���һ�����Ƿ��������ջ���� 
			}
		}
		if(qstack[i].empty())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	
	return 0;
}
