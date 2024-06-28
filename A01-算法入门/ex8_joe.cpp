#include<iostream>
#include<cstring>
using namespace std;

int a[105][105], b[105][105];

int main() {
    int n, m, g;
    cin >> n >> m;

    // Read the input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // Process the board
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            g = 0;
            if (a[i][j] == 1) {
                b[i][j] = 9;
            } else {
                if (i - 1 >= 0 && a[i - 1][j] == 1) g += 1;
                if (i + 1 < n && a[i + 1][j] == 1) g += 1;
                if (j - 1 >= 0 && a[i][j - 1] == 1) g += 1;
                if (j + 1 < m && a[i][j + 1] == 1) g += 1;
                if (i + 1 < n && j + 1 < m && a[i + 1][j + 1] == 1) g += 1;
                if (i - 1 >= 0 && j - 1 >= 0 && a[i - 1][j - 1] == 1) g += 1;
                if (i + 1 < n && j - 1 >= 0 && a[i + 1][j - 1] == 1) g += 1;
                if (i - 1 >= 0 && j + 1 < m && a[i - 1][j + 1] == 1) g += 1;
                b[i][j] = g;
            }
        }
    }

    // Output the result
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
