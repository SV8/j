#include <iostream>
#include <string>
using namespace std;

int main() {
	
	string s;
	cin >> s;
	
	while (s.size() > 1 ) { // 只剩一个字符时，结束循环
		int index;
		// 搜索数字 
		for(int i=0; i<s.size(); i++) {
			// 要比它后面相邻的数字小；没找到就选最末尾那个
			if(s[i] < s[i+1] || i == s.size()-1) { 
				index = i;
				break;
			}
		}
		// 删除数字（调用string的erase函数） 
		s.erase(index, 1);
		// 打印本轮结果 
		cout << s << endl;
	}
}
