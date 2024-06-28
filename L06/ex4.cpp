#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int n; //人数
	int h; //身高
	double t = 0; //临时变量，保存总的身高
	
	cin >> n; //输入总人数 
	
	for(int i=0; i<n; i+=1) {
		cin >> h; //依次输入一个人的身高 
		t += h; //把结果累加到临时变量 
	}
	printf("平均身高为: %.2f", t/n);
}
