#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[1002][1002];
int dis[1002][1002];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, ans = 0;
    queue<pair<int, int> > Q;
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) Q.push({ i, j });
            if (board[i][j] == 0) dis[i][j] = -1;
        }
    }
    while (!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        for (int i = 0; i < 4; i++) {
            int x = cur.X + dx[i];
            int y = cur.Y + dy[i];
            if (x < 0 || x >= N || y < 0 || y >= M) continue;
            if (dis[x][y] >= 0) continue;
            dis[x][y] = dis[cur.X][cur.Y] + 1;
            Q.push({ x, y });
            ans = dis[x][y];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (dis[i][j] == -1) {
                cout << -1;
                return 0;
            }
        }
    }
    cout << ans;
    return 0;
}