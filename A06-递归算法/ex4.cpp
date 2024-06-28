/*
斐波那契数列为 1 , 1 , 2 , 3 , 5 , 8 , 13 , 21 ,…，其元素产生的规则是前两个数为 1 ，从第三个数开始每个数等于它前面两个数之和。
已知任意一个正整数可以表示为若干个互不相同的斐波那契数之和。例如： 36=21+13+2 。
下面的程序是由键盘输入一个正整数 n ，输出组成 n 的互不相同的斐波那契数。
算法说明：
( 1 ）寻找小于等于 n 的最大斐波那契数 a ，并以 a 作为组成 n 的一个数。
( 2 ）若 n ≠ a ，则以 n - a 作为 n 的新值，重复步骤（ 1 )。若 a = n ，则结束。

36=21+13+2
34
2
1
1
*/

#include<iostream>
#include<cstdio>
using namespace std;
int n;
bool first;

int find(int n) {
    int a, b, c;
    a = 1; b = 1;
    do {
        c = a + b;
        a = b;  // ① 更新变量的值，使a为b，b为c
        b = c;
    } while (b < n); // ② 修改循环条件
    if (b == n)  // ③ 判断最后的b是否等于n
        return b;
    else
        return a;  // ④ 若当前b不符合条件，即b>n，返回前一个斐波那契数a
}

void p(int n) {
    int a;
    a = find(n);
    if (first) {
        printf("%4d", a);
        first = false;
    } else
        printf("+%4d", a);  // ⑤ 打印时的格式，若不是第一次打印，前面加上'+'
    if (a < n)
        p(n - a);  // ⑥ 递归调用函数，以继续寻找剩余部分的斐波那契数
}

int main() {
    cin >> n;
    first = true; // 是否位第一个数，打印第一个无需 + 号 
    printf("%5d=", n);
    p(n);
    cout << endl;
    return 0;
}


