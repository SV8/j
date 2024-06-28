#include <iostream>
using namespace std;

int main() {
	int t;	// 共输入多少行数据
	int n;	// 当前这一行，包含多少个整数 
	int k;	// 当前行满足条件（求最小和）的k值 
	int sum = 0;	// 计算得到的最小和
	int sumt = 0;	// 保存中间结果
	int result[t];	// 保存每一行的k值，打印这个数组即可 
	 
	cin >> t; 
	
	for(int i=0; i<t; i++) {
		
		cin >> n;	// 该行整数的个数 
		int numbers[n];	// 数组numbers，保存这一行的整数 
		
		//sum = 0;	// 当前行的最小和初始化为0 
		
		// 逐个输入
		for (int j=0; j<n; j++) {
			cin >> numbers[j];
		}
		
		// k的范围是1~30000，计算每个k值对应的和，并追踪最小的和 
		for (int kt=1; kt<30000; kt++) {
			sumt = 0;
			for(int j=0; j<n; j++) {
				if (kt - numbers[j] >= 0)
					sumt += kt - numbers[j];
				else
					sumt += numbers[j] - kt;
			}
			
			// 比较大小 
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
		
		// 结果保存到result数组 
		result[i] = sum;
	}
	
	// 打印最终结果 
	for(int i=0; i<t; i++)
		cout << result[i] << endl;
	
	return 0;
}
