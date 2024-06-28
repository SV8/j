#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int mp[3][6], book[11];
int sum = 0;

int solve() {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) {
            if (mp[i][j] > mp[i][j+1] || mp[i][j] > mp[i+1][j])
                return 0;
        }
    }
    return 1;
}

void dfs(int num) {
    if (num == 10) {
        if (solve())
            sum++;
        return;
    }
    for (int i = 1; i <= 10; i++) {
        if (book[i] == 0) {
            book[i] = 1;
            mp[num / 5][num % 5] = i;
            dfs(num + 1);
            book[i] = 0;
        }
    }
}

int main() {
    mp[0][5] = 11; // 在判断是否符合条件时,涉及到了i+1和j+1,要保证超出范围的区域无影响
    mp[1][5] = 11;
    for (int i = 0; i < 5; i++)
        mp[2][i] = 11;
    dfs(0);
    printf("%d\n", sum);
    return 0;
}
