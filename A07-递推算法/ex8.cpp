#include <iostream>

using namespace std;

int paidui(int n) {

    long long d[31] = {0};

    // 初始化
    d[0] = 1; // 空方案，方案数 1 
    d[1] = 1; // 1个学生，只能是M，方案数 1
    d[2] = 2; // 2个学生，MM,FF，方案数 2
    d[3] = 4; // 3个学生，MMM,FFF,MFF,FFM，方案数 4 
    d[4] = 7; // 4个学生，MMMM,FFFF,MMFF,FFMM,MFFM,MFFF,FFFM，方案数 7 
 
 	/* n>4
	如果第i个是M，前面的i-1个人只要合法排列即可，方案数就是d[i-1]
	如果第i个是F，第i-1个必须是F，前面的i-2个人有两种情况：
		1)只要合法排列即可，方案数是d[i-2]
		2)第i-2是F,第i-3是M，方案数是d[i-4] 
	综上所述，n>4时递推公式为 d[i] = d[i-1] + d[i-2] + d[i-4]
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
