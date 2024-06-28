#include<iostream>
using namespace std;
int main(){
	
	int a = 0;	// 行数 
	int n = 0;	// 当前行的整数个数 
	int c = 0;	// 保存中间结果 
	int k;		// 当前行最小和对应的k值 
	int cn;		// 当前行最小和 
	int u;		// 绝对值中间结果 
	
	cin >> a;
	int p[a];	// 数组p保存每一行的k值，最后打印出来即可 
	
	for(int i = 0;i < a;i += 1){
		cin >> n;
		int b[n];	// 当前行的数字保存到数组b 
		
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
