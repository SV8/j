/*
阅读程序（程序输入不超过数组或字符串定义的范围）

“鸡蛋掉落”问题：
给你 k 枚相同的鸡蛋，并可以使用一栋从第 1 层到第 n 层共有 n 层楼的建筑。
已知存在楼层 f ，满足 0 <= f <= n ，任何从 高于 f 的楼层落下的鸡蛋都会碎，从 f 楼层或比它低的楼层落下的鸡蛋都不会破。
每次操作，你可以取一枚没有碎的鸡蛋并把它从任一楼层 x 扔下（满足 1 <= x <= n）。如果鸡蛋碎了，你就不能再次使用它。如果某枚鸡蛋扔下后没有摔碎，则可以在之后的操作中重复使用这枚鸡蛋。
请你计算并返回要确定 f 确切的值的最小操作次数是多少？

*/

#include <algorithm>
#include <iostream>
#include <limits>

using namespace std;

const int MAXN = 105;
const int MAXK = 105;

int h[MAXN][MAXK];

int min_called = 0;

int f(int n, int m)
{
    if (m == 1) return n;
    if (n == 0) return 0;

    int ret = numeric_limits<int>::max();
    for (int i = 1; i <= n; i++) {
        min_called++;
        //printf("f(%d,%d) = min(%d, max(f(%d,%d),f(%d,%d)) + 1\n", n, m, ret, n - i, m, i - 1, m - 1);
        printf("n=%d, m=%d, i=%d\n", n, m, i);
        ret = min(ret, max(f(n - i,m), f(i - 1, m - 1)) + 1);
    }
    return ret;
}

int g(int n, int m)
{
    for (int i = 1;i <= n; i++)
        h[i][1]= i;
    for (int j = 1;j<= m; j++)
        h[0][j]= 0;

    for (int i= 1; i <= n; i++){
        for (int j= 2; j <= m; j++){
            h[i][j] = numeric_limits<int>::max();
            for (int k = 1;k <= i;k++)
            h[i][j]= min(
                h[i][j],
                max(h[i - k][j],h[k - 1][j - 1]) +1);
        }
    }

    return h[n][m];
}

void show_g(int n, int m) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            printf("%d ", h[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n,m;
    cin >> n >> m;
    //cout << f(n, m) << endl << g(n, m)<< endl;
    cout << g(n, m) << endl;
    show_g(n, m);
    //cout << min_called << endl;
    return 0;
}

/*
当输入为 7 3 时，代码第19 行ret = min(ret, max(f(n - i,m), f(i - 1, m - 1)) + 1)，用来取最小值的 min 函数一共执行了多少次？

f(0,x) = 0
f(x,1) = x

i = 1
f(7,3) = min(999999999, max(f(6,3),f(0,2)) + 1
f(6,3) = min(999999999, max(f(5,3),f(0,2)) + 1
f(5,3) = min(999999999, max(f(4,3),f(0,2)) + 1
f(4,3) = min(999999999, max(f(3,3),f(0,2)) + 1
f(3,3) = min(999999999, max(f(2,3),f(0,2)) + 1
f(2,3) = min(999999999, max(f(1,3),f(0,2)) + 1
f(1,3) = min(999999999, max(f(0,3),f(0,2)) + 1
f(0,3) = 0

i = 2
f(7,3) = min(999999999, max(f(5,3),f(1,2)) + 1
f(5,3) = min(999999999, max(f(4,3),f(1,2)) + 1, f(1,2) = min(999999999, max(f(0,2),f(1,1)) + 1
f(4,3) = min(999999999, max(f(3,3),f(1,2)) + 1
f(3,3) = min(999999999, max(f(2,3),f(1,2)) + 1
f(2,3) = min(999999999, max(f(1,3),f(1,2)) + 1
f(1,3) = min(999999999, max(f(0,3),f(1,2)) + 1
f(0,3) = 0
f(0,2) = 0
f(1,1) = 1

i = 3
f(7,3) = min(999999999, max(f(4,3),f(2,2)) + 1
f(4,3) = min(999999999, max(f(3,3),f(2,2)) + 1, f(2,2) = min(999999999, max(f(1,2),f(1,1)) + 1
f(3,3) = min(999999999, max(f(2,3),f(2,2)) + 1
f(2,3) = min(999999999, max(f(1,3),f(2,2)) + 1
f(1,3) = min(999999999, max(f(0,3),f(2,2)) + 1
f(0,3) = 0
f(1,2) = 1
f(1,1) = 1


g的时间复杂度分析

for (int i = 1; i <= n; i++)
    h[i][1] = i;
O(n)

for (int j = 1; j <= m; j++)
    h[0][j] = 0;
O(m)

for (int i = 1; i <= n; i++) {
    for (int j = 2; j <= m; j++) {
        h[i][j] = numeric_limits<int>::max();
        for (int k = 1; k <= i; k++) {
            h[i][j] = min(h[i][j], max(h[i - k][j], h[k - 1][j - 1]) + 1);
        }
    }
}

(m-1) * (1~n)
1+2+3+...+n = n(n+1)/2
(m-1) * n(n+1)/2 = O(mn^2)
 */