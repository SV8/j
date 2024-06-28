#include <iostream>
#include <algorithm>
using namespace std;

// 用于判断是否可以通过移除不超过 M 块岩石来确保最短跳跃距离至少为 mid
bool canAchieve(int rocks[], int N, int L, int M, int mid) {
    int removed = 0;
    int prev = 0; // 上一个没有被移除的岩石位置，初始化为起点位置0
    for (int i = 0; i < N; ++i) {
        if (rocks[i] - prev < mid) {
            // 如果当前岩石与上一个岩石的距离小于 mid，则移除当前岩石
            removed++;
            if (removed > M) {
                return false;
            }
        } else {
            // 否则不移除当前岩石，更新上一个岩石的位置
            prev = rocks[i];
        }
    }
    // 最后还需要确保终点和最后一个岩石之间的距离也满足至少为 mid
    if (L - prev < mid) {
        removed++;
    }
    return removed <= M;
}

int main() {
    int L, N, M;
    cin >> L >> N >> M;
    int rocks[N];
    for (int i = 0; i < N; ++i) {
        cin >> rocks[i];
    }

    // 二分查找最短跳跃距离的最大值
    int left = 1, right = L, result = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canAchieve(rocks, N, L, M, mid)) {
            result = mid; // 记录当前能达到的最大最小跳跃距离
            left = mid + 1; // 尝试找更大的
        } else {
            right = mid - 1; // 尝试找更小的
        }
    }

    cout << result << endl;
    return 0;
}

