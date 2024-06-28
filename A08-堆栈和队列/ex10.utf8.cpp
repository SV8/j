#include <iostream>
#include <stack>
//#include <bits/stdc++.h>
using namespace std;

int main() {
	int q;
	cin >> q;	// 一共 q 组数据 
	int n[q];	// 每组的序列长度 
	stack<int> qstack[q];	// 每组分配一个stack 
	int pushed[q][100005];	// q组入栈序列
	int poped[q][100005];	// q组出栈序列 
	
	// 首先输入所有数据并保存 
	for(int i=0; i<q; i++) {
		cin >> n[i];
		for(int j=0; j<n[i]; j++) {
			cin >> pushed[i][j];
		}
		for(int j=0; j<n[i]; j++) {
			cin >> poped[i][j];
		}
	}
	
	// 开始验证 
	for(int i=0; i<q; i++) {
		int index = 0;	// 出栈序列的下标 
		for(int j=0; j<n[i]; j++) {
			qstack[i].push(pushed[i][j]);	// 入栈序列的下一个数，入栈
			while(!qstack[i].empty() && (qstack[i].top() == poped[i][index])) {	// 如果满足出栈条件，则执行出栈操作 
				qstack[i].pop();	// 出栈
				index++;	// 检查出栈序列中的下一个数是否仍满足出栈条件 
			}
		}
		if(qstack[i].empty())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	
	return 0;
}
