/*

最小区间覆盖问题

给出 n 个区间，第 i 个区间的左右端点是 [ai,bi]。现在要在这些区间中选出若干个，
使得区间 [0,m] 被所选区间的并覆盖（即每一个$ 0≤i≤m$ 都在某个所选的区间中)。
保证答案存在，求所选区间个数的最小值。
 
输入第一行包含两个整数 n 和 m (1≤n≤5000,1≤m≤10^9)
接下来 n 行，每行两个整数 ai,bi(0≤ai,bi≤m)。

提示：使用贪心法解决这个问题。先用 O(n^2) 的时间复杂度排序，然后贪心选择这些区间。
试补全程序。

*/

#include <iostream>
using namespace std;

const int MAXN = 5000;
int n, m;
struct segment
{
	int a, b;
} A[MAXN];

void sort() // 排序
{
	for (int i = 0; i < n; i++)
		for (int j = 1; j < n; j++)
			if (A[j].a<A[j-1].a)
			{
				segment t = A[j];
				A[j]=A[j-1];
                A[j-1]=t;
			}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> A[i].a >> A[i].b;
	sort();
	int p = 1;
	for (int i = 1; i < n; i++)
		if (A[i].b>A[p-1].b)
			A[p++] = A[i];
	n = p;
	int ans =0, r = 0;
	int q = 0;
	while (r < m)
	{
		while (q<n&&A[q].a<=r)
			q++;
		r=max(r,A[q].b);
		ans++;
	}
	cout << ans << endl;
	return 0;
}