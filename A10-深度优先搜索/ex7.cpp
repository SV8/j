#include <iostream>

using namespace std;

const int MAX_N = 5;
const int MAX_M = 5;

int N, M, T;

int startX, startY, endX, endY; //�����յ��λ�� 
int maze[MAX_N + 1][MAX_M + 1]; //�Թ����񲼾֣���ά���飩 
bool visited[MAX_N + 1][MAX_M + 1]; //��¼�����Ƿ񱻷��ʹ� 
int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // �ƶ����ĸ����� 
int totalPaths = 0; //����㵽�յ������·����

void dfs(int x, int y) {
	
    // �ɹ��ִ��յ㣬���Ӽ��� 1 �� 
    if (x == endX && y == endY) {
        totalPaths++;
        return;
    }
    
    // ÿ�η���һ�����Ӻ���Ϊ�ѷ��ʡ�
    visited[x][y] = true;

    // ���ĸ�����̽����ǰ��һ�� 
    for (int i = 0; i < 4; i++) {
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];
        
        // ��鵱ǰλ�ã�1.�Ƿ��ڱ߽����� 2.����û�б����ʹ� 3.����û��ʯͷ�赲 
        if (newX >= 1 && newX <= N && newY >= 1 && newY <= M && !visited[newX][newY] && maze[newX][newY] != -1) {
            dfs(newX, newY); //����λ�ÿ�ʼ�������ݹ���ң�������������� 
        }
    }
    
    // ������ɺ���ݣ�����ǰ���ӱ��Ϊδ���ʣ��Ա�̽������·����
    visited[x][y] = false;
}

int main() {
    cin >> N >> M >> T;
    cin >> startX >> startY >> endX >> endY;

    // ��ʼ�� maze �� visited ���飬maze�� 0 ��ʾ��ͨ��, visited �� false��ʾδ������ 
	for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            maze[i][j] = 0;
            visited[i][j] = false;
        }
    }
    
    // maze �� -1 ��ʾ���ϰ�
    for (int i = 0; i < T; i++) {
        int ox, oy;
        cin >> ox >> oy;
        maze[ox][oy] = -1;
    }

    // ����㿪ʼ�������ݹ�����ĸ�����
    dfs(startX, startY);

    // ������յ�·���� 
    cout << totalPaths << endl;

    return 0;
}
