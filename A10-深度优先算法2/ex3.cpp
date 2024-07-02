//阅读程序（程序输入不超过数组或字符串定义的范围
//假设 int 为 32 位有符号整数类型，输入的 n 是不超过 47000 的自然数、k 是不超过 int 表示范围的自然数

#include <iostream>
using namespace std;

int n,k;

// 通过二分查找：不超过 n 的最大整数，的平方根。
int solve1()
{
    int l = 0, r = n;
    while(l <= r){
        int mid = (l + r) / 2;
        if (mid * mid <= n) l = mid + 1;
        else r = mid - 1;
    }
    return l - 1;
}

double solve2(double x)
{
    if (x == 0) return x;
    for (int i = 0; i < k; i++) {
        x = (x + n / x) / 2;
        printf("i = %d, x = %f\n", i, x);
    }
    return x;
}

int main()
{
    cin >> n >> k;
    //cout << solve1() << endl;
    int s = solve1();
    printf("slove1() = %d\n", s);
    double ans = solve2(s);
    printf("slove2(%d) = %f\n", s, ans);
    cout << ans << ' ' << (ans * ans == n) << endl;
    return 0;
}