#include<cstdio>
#include<cstring>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int n, k;
char mp[100];
int a[100];
int mx;

void dfs(int sum, int len, int num) // 当前的乘积sum  遍历到的位置len  使用的乘号的数量num
{
    // 递归的终止条件
    if(len > n) // 遍历到的位置超过了字符串的长度
        return;
    if(num > k) // 乘号数量超过了规定的数量
        return;
    if(num == k) // 乘号数量已达到规定的数量
    {
        int res = 0;
        for(int i = len + 1; i <= n; i++) // 计算最后一个乘号后的数字
            res = res * 10 + a[i];
        sum *= res; // 乘上最后一个乘号后的数字
        mx = max(mx, sum); // 更新最大值
        return;
    }

    // 枚举乘号的位置
    for(int i = 1; i <= n - len; i++) // 乘号的位置
    {
        int res = 0;
        for(int j = len + 1; j <= len + i && j <= n; j++) // 计算乘号后的数字
            res = res * 10 + a[j];
        dfs(sum * res, len + i, num + 1); // 递归，更新乘积sum，位置len，乘号数量num
    }
    
    return;
}

int main()
{
    mx = 0;
    scanf("%d%d", &n, &k); // 字符串的长度 乘号的数量
    scanf("%s", mp); // 字符串
    int i = 0;
    while(mp[i] != '\0') // 将字符串转换为数字
    {
        a[i + 1] = mp[i] - '0';
        i++;
    }
    dfs(1, 0, 0); // 乘积, 初始位置, 乘号的数量
    printf("%d\n", mx);
    return 0;
}


/*

假设输入为 n=3, k=1, mp="123"，我们来分析每次递归调用时的程序状态：

初始状态：sum=1, len=0, num=0

第一次递归调用：dfs(1, 0, 0)

for(int i = 1; i <= 3 - 0; i++) 依次取 i = 1, i = 2, i = 3

i = 1
res = 0
for(int j = 1; j <= 1; j++)
res = res * 10 + a[j] = 0 * 10 + 1 = 1
递归调用 dfs(1 * 1, 1, 1) = dfs(1, 1, 1)
第二次递归调用：dfs(1, 1, 1)

num == k，进入该条件
res = 0
for(int i = 2; i <= 3; i++)
res = res * 10 + a[i] = 0 * 10 + 2 = 2
res = res * 10 + a[3] = 2 * 10 + 3 = 23
sum *= res = 1 * 23 = 23
mx = max(mx, 23) = 23
返回到第一次递归调用继续

i = 2
res = 0
for(int j = 1; j <= 2; j++)
res = res * 10 + a[j] = 0 * 10 + 1 = 1
res = res * 10 + a[2] = 1 * 10 + 2 = 12
递归调用 dfs(1 * 12, 2, 1) = dfs(12, 2, 1)
第三次递归调用：dfs(12, 2, 1)

num == k，进入该条件
res = 0
for(int i = 3; i <= 3; i++)
res = res * 10 + a[i] = 0 * 10 + 3 = 3
sum *= res = 12 * 3 = 36
mx = max(mx, 36) = 36
返回到第一次递归调用继续

i = 3
res = 0
for(int j = 1; j <= 3; j++)
res = res * 10 + a[j] = 0 * 10 + 1 = 1
res = res * 10 + a[2] = 1 * 10 + 2 = 12
res = res * 10 + a[3] = 12 * 10 + 3 = 123
递归调用 dfs(1 * 123, 3, 1) = dfs(123, 3, 1)
第四次递归调用：dfs(123, 3, 1)

num == k，进入该条件
res = 0
for(int i = 4; i <= 3; i++) 不执行，因为 i 超出范围
sum *= res = 123 * 0 = 0（不影响结果）

最终 mx 的值为 36，这是最大的乘积。

*/
