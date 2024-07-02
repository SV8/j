/*

oibh 被突来的洪水淹没了，还好 oibh 总部有在某些重要的地方起一些围墙。用 * 号表示，而一个四面被围墙围住的区域洪水是进不去的。
oibh 总部内部也有许多重要区域，每个重要区域在图中用一个 0 表示。
现在给出 oibh 的围墙建设图，问有多少个没被洪水淹到的重要区域。
 
输入格式
第一行为两个正整数 x,y(1≤x,y≤1000)。
接下来 x 行，每行 y 个整数，由 * 和 0 组成，表示 oibh 总部的建设图。

输出格式
输出没被水淹没的 oibh 总部的 0 的数量。

样例组输入#1
4 5
00000
00*00
0*0*0
00*00

样例组输出#1
1

样例组输入#2
5 5
*****
*0*0*
**0**
*0*0*
*****

样例组输出#2
5

*/

#include <iostream>

using namespace std;

const int MAX = 1000;
char grid[MAX][MAX];

void floodFill(int x, int y, int maxX, int maxY) {
    if (x < 0 || y < 0 || x >= maxX || y >= maxY || grid[x][y] != '0') {
        return;
    }

    grid[x][y] = 'f'; // 'f' stands for flooded

    // Check all four directions
    floodFill(x + 1, y, maxX, maxY);
    floodFill(x - 1, y, maxX, maxY);
    floodFill(x, y + 1, maxX, maxY);
    floodFill(x, y - 1, maxX, maxY);
}

int main() {
    int x, y;
    cin >> x >> y;

    // Read the grid
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> grid[i][j];
        }
    }

    // Flood fill from the borders
    for (int i = 0; i < x; i++) {
        floodFill(i, 0, x, y);
        floodFill(i, y - 1, x, y);
    }

    for (int j = 0; j < y; j++) {
        floodFill(0, j, x, y);
        floodFill(x - 1, j, x, y);
    }

    int safeCount = 0;

    // Count the safe regions
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (grid[i][j] == '0') {
                safeCount++;
            }
        }
    }

    cout << safeCount << endl;

    return 0;
}