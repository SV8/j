// ACGO - A20928.��������ţ

#include <iostream>
#include <algorithm>

using namespace std;

// ����ڸ�����С�����������ܷ����Cͷţ
bool canPlaceCows(int stalls[], int N, int C, int minDist) {
    int count = 1;  // ���õ�һͷţ
    int lastPos = stalls[0];  // ���ڵ�һ������

    for (int i = 1; i < N; ++i) {
        if (stalls[i] - lastPos < minDist) {
            continue;  // �����޷�����ţ�ĸ���
        }
        count++;
        lastPos = stalls[i];  // ������һͷţ
        if (count == C) { // �ѷ�����Cͷţ 
            return true;
        }
    }
    return false; // δ������Cͷţ 
}

int main() {
    int N, C;
    cin >> N >> C;
    int stalls[N]; // N�������λ�� 
    
    for (int i = 0; i < N; ++i) {
        cin >> stalls[i];
    }

    // �������λ��
    sort(stalls, stalls + N);

    // ���ֲ���������С����
    int low = 1;  // ��С���벻��Ϊ0
    int high = stalls[N-1] - stalls[0];  // ������Ϊ��һ�������һ������֮��ľ���
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPlaceCows(stalls, N, C, mid)) {
            result = mid;  // ��¼��ǰ������������С����
            low = mid + 1;  // ���Ը������С����
        } else {
            high = mid - 1;  // ���Ը�С�ľ���
        }
    }

    cout << result << endl;

    return 0;
}
