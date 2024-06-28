#include <iostream>
using namespace std;

const int MAX_N = 5;
const int MAX_M = 5;

int N, M, T;

int startX, startY, endX, endY; //起点和终点的位置 
int maze[MAX_N + 1][MAX_M + 1]; //迷宫方格布局（二维数组） 
bool visited[MAX_N + 1][MAX_M + 1]; //记录方格是否被访问过 
int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 移动的四个方向 
int totalPaths = 0; //从起点到终点的所有路径数

void dfs(int x, int y) {
	
    // 成功抵达终点，增加计数 1 次 
    if (x == endX && y == endY) {
        totalPaths++;
        return;
    }
    
    // 每次访问一个格子后标记为已访问。
    visited[x][y] = true;

    // 朝四个方向探索，前进一格 
    for (int i = 0; i < 4; i++) {
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];
        
        // 检查当前位置：1.是否在边界以内 2.并且没有被访问过 3.并且没有石头阻挡 
        if (newX >= 1 && newX <= N && newY >= 1 && newY <= M && !visited[newX][newY] && maze[newX][newY] != -1) {
            dfs(newX, newY); //从新位置开始，继续递归查找（深度优先搜索） 
        }
    }
    
    // 搜索完成后回溯，将当前格子标记为未访问，以便探索其他路径。
    visited[x][y] = false;
}

int main() {
    cin >> N >> M >> T;
    cin >> startX >> startY >> endX >> endY;

    // 初始化 maze 和 visited 数组，maze中 0 表示可通行, visited 中 false 表示未被访问 
	for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            maze[i][j] = 0;
            visited[i][j] = false;
        }
    }
    
    // maze 中 -1 表示有障碍
    for (int i = 0; i < T; i++) {
        int ox, oy;
        cin >> ox >> oy;
        maze[ox][oy] = -1;
    }

    // 从起点开始搜索，递归遍历四个方向。
    dfs(startX, startY);

    // 输出最终的路径数 
    cout << totalPaths << endl;

    return 0;
}
