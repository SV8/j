#include <iostream>
#include <algorithm>
using namespace std;

// �����ж��Ƿ����ͨ���Ƴ������� M ����ʯ��ȷ�������Ծ��������Ϊ mid
bool canAchieve(int rocks[], int N, int L, int M, int mid) {
    int removed = 0;
    int prev = 0; // ��һ��û�б��Ƴ�����ʯλ�ã���ʼ��Ϊ���λ��0
    for (int i = 0; i < N; ++i) {
        if (rocks[i] - prev < mid) {
            // �����ǰ��ʯ����һ����ʯ�ľ���С�� mid�����Ƴ���ǰ��ʯ
            removed++;
            if (removed > M) {
                return false;
            }
        } else {
            // �����Ƴ���ǰ��ʯ��������һ����ʯ��λ��
            prev = rocks[i];
        }
    }
    // �����Ҫȷ���յ�����һ����ʯ֮��ľ���Ҳ��������Ϊ mid
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

    // ���ֲ��������Ծ��������ֵ
    int left = 1, right = L, result = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canAchieve(rocks, N, L, M, mid)) {
            result = mid; // ��¼��ǰ�ܴﵽ�������С��Ծ����
            left = mid + 1; // �����Ҹ����
        } else {
            right = mid - 1; // �����Ҹ�С��
        }
    }

    cout << result << endl;
    return 0;
}

