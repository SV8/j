/*
一个由'A'和'B'组成的字符串s，每次可以删除"AB"或"BB"子串，剩余的部分会连接起来。找出最短的字符串长度。
*/

#include <bits/stdc++.h>
using namespace std;
int t;
string s;
int main() {
    cin >> s;
    int n = s.size();
    int a = 0;
    int b = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            a++;
        } else {
            if (a > 0) a--;
            else b++;
        }
    }
    if (a == 0) {
        cout << ((b & 1) == 1 ? 1 : 0);
    } else {
        if (b != 0) {
            int ans = 0;
            if (b & 1) ans = 1;
            cout << a + ans;
        } else {
            cout << a;
        }
    }
    return 0;
}
