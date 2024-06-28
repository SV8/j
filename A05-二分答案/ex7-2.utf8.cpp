/*这项比赛将在一条笔直的河道中进行，河道中分布着一些巨大岩石。
组委会已经选择好了两块岩石作为比赛起点和终点。在起点和终点之间，有 N 块岩石（不含起点和终点的岩石）。
在比赛过程中，选手们将从起点出发，每一步跳向相邻的岩石，直至到达终点。

为了提高比赛难度，组委会计划移走一些岩石，使得选手们在比赛过程中的最短跳跃距离尽可能长。
由于预算限制，组委会至多从起点和终点之间移走 M 块岩石（不能移走起点和终点的岩石）。

输入格式
第一行包含三个整数 L,N,M, 分别表示起点到终点的距离，起点和终点之间的岩石数，以及组委会至多移走的岩石数。保证 L≥1 且 N≥M≥0。
接下来 N 行，每行一个整数，第 i 行的整数0<Di<L, 表示第 i 块岩石与起点的距离。这些岩石按与起点距离从小到大的顺序给出，且不会有两个岩石出现在同一个位置。

输出格式
一个整数，即最短跳跃距离的最大值。

分析： 
距离是L
D[N], 其中的元素D[i]表示第i块岩石与起点的距离
从其中移走M块，使得最短跳跃距离尽可能长
*/
#include <iostream>
#include <algorithm>
using namespace std;

int countRemovedRocks(int rocks[], int n, int m, int d) {
	int count = 0;
	int before = 0;
	for(int i=0; i<n; i++) {
		if(rocks[i] - before >= d) { // 相邻石块的间距足够，无需移除 
			before = rocks[i];
		}
		else { // 相邻石块的间距不够，移除当前石块 
			count++;
		}
	}
	return count;
}

int main() {
	int L, N, M;
	cin >> L >> N >> M;
	int rocks[N];
	for(int i=0; i<N; i++)
		cin >> rocks[i];
	
	// 二分法查找最短跳跃距离的最大值 
	int left = 1, right = L; // 最小跳跃距离是1，最大跳跃距离是总长度L 
	int mid = 0;
	while(left<=right) {
		mid = (left + right) / 2;
		int c = countRemovedRocks(rocks, N, M, mid);
		if(c < M) { // 移除的石块不足 M 块，尝试更大的最短跳跃距离  
			left = mid + 1;
		} else if (c > M) { // 移除的石块超过 M 块，尝试更小的最短跳跃距离 
			right = mid - 1; 
		} else if (c == M) // 满足条件，结束循环 
			break;
	}
	int ans = mid; // 搜索结束
	cout << ans << endl;
}

