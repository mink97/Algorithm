#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
char table[1002][1002];
int fire[1002][1002];
int dis[1002][1002];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int R, C;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> R >> C;
    queue<pair<int, int>> FQ;
    queue<pair<int, int>> JQ;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> table[i][j];
            if (table[i][j] == '.') {
                dis[i][j] = -1;
                fire[i][j] = -1;
            }
            else if (table[i][j] == 'J') {
                JQ.push({ i, j });
                fire[i][j] = -1;
            }
            else if (table[i][j] == 'F') {
                FQ.push({ i, j });
                dis[i][j] = -1;
            }
        }
    }
    // 불 경로 bfs
    while (!FQ.empty()) {
        pair<int, int> cur = FQ.front(); FQ.pop();
        for (int i = 0; i < 4; i++) {
            int x = cur.X + dx[i];
            int y = cur.Y + dy[i];
            if (x < 0 || x >= R || y < 0 || y >= C) continue;
            if (fire[x][y] >= 0) continue;
            fire[x][y] = fire[cur.X][cur.Y] + 1;
            FQ.push({ x, y });
        }
    }
    // 지훈이 경로 bfs
    while (!JQ.empty()) {
        pair<int, int> cur = JQ.front(); JQ.pop();
        for (int i = 0; i < 4; i++) {
            int x = cur.X + dx[i];
            int y = cur.Y + dy[i];
            if (x < 0 || x >= R || y < 0 || y >= C) {
                cout << dis[cur.X][cur.Y] + 1;
                return 0;
            }
            if (dis[x][y] >= 0 || (fire[x][y] >= 0 && fire[x][y] <= dis[cur.X][cur.Y] + 1)) continue;
            dis[x][y] = dis[cur.X][cur.Y] + 1;
            JQ.push({ x, y });
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}