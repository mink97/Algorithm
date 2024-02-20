#include <bits/stdc++.h>
using namespace std;
int M, N, H;
int board[102][102][102];
int dis[102][102][102];
int dx[6] = { 1, 0, 0, -1, 0, 0 };
int dy[6] = { 0, 1, 0, 0, -1, 0 };
int dz[6] = { 0, 0, 1, 0, 0, -1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M >> N >> H;
    queue<tuple<int, int, int>> Q;
    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> board[i][j][k];
                if (board[i][j][k] == 1) {
                    Q.push(make_tuple(i, j, k));
                }
                if (board[i][j][k] == 0) {
                    dis[i][j][k] = -1;
                }
            }
        }
    }
    int day = 0;
    while (!Q.empty()) {
        int curX, curY, curZ;
        tie(curX, curY, curZ) = Q.front(); Q.pop();
        for (int i = 0; i < 6; i++) {
            int x = curX + dx[i];
            int y = curY + dy[i];
            int z = curZ + dz[i];
            if (x < 0 || y < 0 || z < 0 || \
                x >= N || y >= M || z >= H) continue;
            if (dis[x][y][z] >= 0) continue;
            dis[x][y][z] = dis[curX][curY][curZ] + 1;
            Q.push(make_tuple(x, y, z));
            day = dis[x][y][z];
        }
    }
    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (dis[i][j][k] == -1) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    cout << day;
    return 0;
}