/*
现有用字符标记像素颜色的 8×8 图像。颜色填充的操作描述如下：给定起始像素的位置待填充的颜色，
将起始像素和所有可达的像素（可达的定义：经过一次或多次的向上、下、左、右四个方向移动所能到达且
终点和路径上所有像素的颜色都与起始像素颜色相同），替换为给定的颜色。
 
试补全程序。

 */

#include "bits/stdc++.h"
using namespace std;

const int ROWS = 8;
const int COLS = 8;

struct Point {
    int r, c;
    Point(int r, int c): r(r), c(c) {}
};

bool is_valid(char image[ROWS][COLS], Point pt, char prev_color, char new_color) {
    int r = pt.r;
    int c = pt.c;
    return (0 <= r && r < ROWS && 0 <= c && c < COLS &&
            image[r][c] == prev_color && image[r][c] != new_color);
}

void flood_fill(char image[ROWS][COLS], Point cur, char new_color) {
    queue<Point> queue;
    queue.push(cur);

    char prev_color = image[cur.r][cur.c];
    image[cur.r][cur.c] = new_color;

    while (!queue.empty()) {
        Point pt = queue.front();
        queue.pop();

        Point points[4] = {Point(pt.r + 1, pt.c), Point(pt.r - 1, pt.c),
                           Point(pt.r, pt.c + 1), Point(pt.r, pt.c - 1)};
        for (auto p : points) {
            if (is_valid(image, p, prev_color, new_color)) {
                image[p.r][p.c] = new_color;
                queue.push(p);
            }
        }
    }
}

int main() {
    char image[ROWS][COLS] = {{'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g'},
                              {'g', 'g', 'g', 'g', 'g', 'g', 'r', 'r'},
                              {'g', 'r', 'r', 'g', 'g', 'r', 'g', 'g'},
                              {'g', 'b', 'b', 'b', 'b', 'r', 'g', 'r'},
                              {'g', 'g', 'g', 'b', 'b', 'r', 'g', 'r'},
                              {'g', 'g', 'g', 'b', 'b', 'b', 'b', 'r'},
                              {'g', 'g', 'g', 'g', 'g', 'b', 'g', 'g'},
                              {'g', 'g', 'g', 'g', 'g', 'b', 'b', 'g'}};

    Point cur(4, 4);
    char new_color = 'y';

    flood_fill(image, cur, new_color);

    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            cout << image[r][c] << ' ';
        }
        cout << endl;
    }

    return 0;
}