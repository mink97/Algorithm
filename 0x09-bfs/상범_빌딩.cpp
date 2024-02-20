#include <bits/stdc++.h>
using namespace std;
int R, C, L;
char table[32][32][32];
int dis[32][32][32];
int dx[6] = { 1, 0, 0, -1, 0, 0 };
int dy[6] = { 0, 1, 0, 0, -1, 0 };
int dz[6] = { 0, 0, 1, 0, 0, -1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> L >> R >> C;
    while (!(L == 0 && R == 0 && C == 0)) {
        queue<tuple<int, int, int>> Q;
        fill(&dis[0][0][0], &dis[L - 1][R - 1][C], -1);
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                for (int k = 0; k < C; k++) {
                    cin >> table[i][j][k];
                    if (table[i][j][k] == 'S') {
                        Q.push({ i, j, k });
                        dis[i][j][k] = 0;
                    }
                    else if (table[i][j][k] == '#') {
                        dis[i][j][k] = 0;
                    }
                }
            }
        }
        bool flag = false;
        while (!Q.empty()) {
            int curX, curY, curZ;
            tie(curZ, curX, curY) = Q.front(); Q.pop();
            if (table[curZ][curX][curY] == 'E') {
                cout << "Escaped in " << dis[curZ][curX][curY] << " minute(s).\n";
                flag = true;
                break;
            }
            for (int i = 0; i < 6; i++) {
                int x = curX + dx[i];
                int y = curY + dy[i];
                int z = curZ + dz[i];
                if (x < 0 || x >= R || y < 0 || y >= C || z < 0 || z >= L) continue;
                if (dis[z][x][y] >= 0) continue;
                Q.push({ z, x, y });
                dis[z][x][y] = dis[curZ][curX][curY] + 1;
            }
        }
        if (!flag)
            cout << "Trapped!\n";
        cin >> L >> R >> C;
    }

    return 0;
}