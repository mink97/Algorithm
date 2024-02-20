#include <bits/stdc++.h>
using namespace std;
int T;
string table[1002];
int dis[1002][1002];
int fire[1002][1002];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T--) {
        int W, H;
        cin >> W >> H;
        fill(&dis[0][0], &dis[H - 1][W], -1);
        fill(&fire[0][0], &fire[H - 1][W], -1);
        queue<pair<int, int>> Q;
        queue<pair<int, int>> FQ;
        for (int i = 0; i < H; i++) {
            cin >> table[i];
            for (int j = 0; j < table[i].size(); j++) {
                if (table[i][j] == '#') {
                    dis[i][j] = 0;
                    fire[i][j] = 0;
                }
                else if (table[i][j] == '@') {
                    Q.push({ i, j });
                    dis[i][j] = 0;
                }
                else if (table[i][j] == '*') {
                    FQ.push({ i, j });
                    fire[i][j] = 0;
                }
            }
        }
        // fire 경로 확인
        while (!FQ.empty()) {
            int curX, curY;
            tie(curX, curY) = FQ.front(); FQ.pop();
            for (int i = 0; i < 4; i++) {
                int x = curX + dx[i];
                int y = curY + dy[i];
                if (x < 0 || x >= H || y < 0 || y >= W) continue;
                if (fire[x][y] >= 0) continue;
                fire[x][y] = fire[curX][curY] + 1;
                FQ.push({ x, y });

            }
        }
        // 지훈이 경로 확인
        bool isEscaped = false;
        while (!Q.empty() && !isEscaped) {
            int curX, curY;
            tie(curX, curY) = Q.front(); Q.pop();
            for (int i = 0; i < 4; i++) {
                int x = curX + dx[i];
                int y = curY + dy[i];
                if (x < 0 || x >= H || y < 0 || y >= W) {
                    cout << dis[curX][curY] + 1 << '\n';
                    isEscaped = true;
                    break;
                }
                if (dis[x][y] >= 0 || (fire[x][y] >= 0 && dis[curX][curY] + 1 >= fire[x][y])) continue;
                Q.push({ x, y });
                dis[x][y] = dis[curX][curY] + 1;
            }
        }
        if (!isEscaped) {
            cout << "IMPOSSIBLE\n";
        }
    }

    return 0;
}