// ACGO - A20928.进击的奶牛

#include <iostream>
#include <algorithm>

using namespace std;

// 检查在给定最小距离的情况下能否放置C头牛
bool canPlaceCows(int stalls[], int N, int C, int minDist) {
    int count = 1;  // 放置第一头牛
    int lastPos = stalls[0];  // 放在第一个隔间

    for (int i = 1; i < N; ++i) {
        if (stalls[i] - lastPos < minDist) {
            continue;  // 跳过无法放置牛的隔间
        }
        count++;
        lastPos = stalls[i];  // 放置下一头牛
        if (count == C) { // 已放置完C头牛 
            return true;
        }
    }
    return false; // 未放置完C头牛 
}

int main() {
    int N, C;
    cin >> N >> C;
    int stalls[N]; // N个隔间的位置 
    
    for (int i = 0; i < N; ++i) {
        cin >> stalls[i];
    }

    // 排序隔间位置
    sort(stalls, stalls + N);

    // 二分查找最大的最小距离
    int low = 1;  // 最小距离不能为0
    int high = stalls[N-1] - stalls[0];  // 最大距离为第一个和最后一个隔间之间的距离
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPlaceCows(stalls, N, C, mid)) {
            result = mid;  // 记录当前满足条件的最小距离
            low = mid + 1;  // 尝试更大的最小距离
        } else {
            high = mid - 1;  // 尝试更小的距离
        }
    }

    cout << result << endl;

    return 0;
}
