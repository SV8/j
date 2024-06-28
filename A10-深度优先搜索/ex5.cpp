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

void dfs(int sum, int len, int num) // ��ǰ�ĳ˻�sum  ��������λ��len  ʹ�õĳ˺ŵ�����num
{
    // �ݹ����ֹ����
    if(len > n) // ��������λ�ó������ַ����ĳ���
        return;
    if(num > k) // �˺����������˹涨������
        return;
    if(num == k) // �˺������Ѵﵽ�涨������
    {
        int res = 0;
        for(int i = len + 1; i <= n; i++) // �������һ���˺ź������
            res = res * 10 + a[i];
        sum *= res; // �������һ���˺ź������
        mx = max(mx, sum); // �������ֵ
        return;
    }

    // ö�ٳ˺ŵ�λ��
    for(int i = 1; i <= n - len; i++) // �˺ŵ�λ��
    {
        int res = 0;
        for(int j = len + 1; j <= len + i && j <= n; j++) // ����˺ź������
            res = res * 10 + a[j];
        dfs(sum * res, len + i, num + 1); // �ݹ飬���³˻�sum��λ��len���˺�����num
    }
    
    return;
}

int main()
{
    mx = 0;
    scanf("%d%d", &n, &k); // �ַ����ĳ��� �˺ŵ�����
    scanf("%s", mp); // �ַ���
    int i = 0;
    while(mp[i] != '\0') // ���ַ���ת��Ϊ����
    {
        a[i + 1] = mp[i] - '0';
        i++;
    }
    dfs(1, 0, 0); // �˻�, ��ʼλ��, �˺ŵ�����
    printf("%d\n", mx);
    return 0;
}


/*

��������Ϊ n=3, k=1, mp="123"������������ÿ�εݹ����ʱ�ĳ���״̬��

��ʼ״̬��sum=1, len=0, num=0

��һ�εݹ���ã�dfs(1, 0, 0)

for(int i = 1; i <= 3 - 0; i++) ����ȡ i = 1, i = 2, i = 3

i = 1
res = 0
for(int j = 1; j <= 1; j++)
res = res * 10 + a[j] = 0 * 10 + 1 = 1
�ݹ���� dfs(1 * 1, 1, 1) = dfs(1, 1, 1)
�ڶ��εݹ���ã�dfs(1, 1, 1)

num == k�����������
res = 0
for(int i = 2; i <= 3; i++)
res = res * 10 + a[i] = 0 * 10 + 2 = 2
res = res * 10 + a[3] = 2 * 10 + 3 = 23
sum *= res = 1 * 23 = 23
mx = max(mx, 23) = 23
���ص���һ�εݹ���ü���

i = 2
res = 0
for(int j = 1; j <= 2; j++)
res = res * 10 + a[j] = 0 * 10 + 1 = 1
res = res * 10 + a[2] = 1 * 10 + 2 = 12
�ݹ���� dfs(1 * 12, 2, 1) = dfs(12, 2, 1)
�����εݹ���ã�dfs(12, 2, 1)

num == k�����������
res = 0
for(int i = 3; i <= 3; i++)
res = res * 10 + a[i] = 0 * 10 + 3 = 3
sum *= res = 12 * 3 = 36
mx = max(mx, 36) = 36
���ص���һ�εݹ���ü���

i = 3
res = 0
for(int j = 1; j <= 3; j++)
res = res * 10 + a[j] = 0 * 10 + 1 = 1
res = res * 10 + a[2] = 1 * 10 + 2 = 12
res = res * 10 + a[3] = 12 * 10 + 3 = 123
�ݹ���� dfs(1 * 123, 3, 1) = dfs(123, 3, 1)
���Ĵεݹ���ã�dfs(123, 3, 1)

num == k�����������
res = 0
for(int i = 4; i <= 3; i++) ��ִ�У���Ϊ i ������Χ
sum *= res = 123 * 0 = 0����Ӱ������

���� mx ��ֵΪ 36���������ĳ˻���

*/
