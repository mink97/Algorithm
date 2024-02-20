#include <bits/stdc++.h>
using namespace std;
int N;
string table[102];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> table[i];
    }
    // 정상
    bool vis[102][102] = { 0, };
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (vis[i][j] == true) continue;
            cnt++;
            queue<pair<int, int>> Q;
            vis[i][j] = true;
            Q.push({ i, j });
            while (!Q.empty()) {
                int cur_x, cur_y;
                tie(cur_x, cur_y) = Q.front(); Q.pop();
                for (int k = 0; k < 4; k++) {
                    int x = cur_x + dx[k];
                    int y = cur_y + dy[k];
                    if (x < 0 || x >= N || y < 0 || y >= N) continue;
                    if (table[x][y] != table[cur_x][cur_y] || vis[x][y] == true) continue;
                    vis[x][y] = true;
                    Q.push({ x, y });
                }
            }
        }
    }
    cout << cnt << ' ';
    // 적록색약
    fill(&vis[0][0], &vis[N - 1][N], false);
    cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (vis[i][j] == true) continue;
            cnt++;
            queue<pair<int, int>> Q;
            vis[i][j] = true;
            Q.push({ i, j });
            while (!Q.empty()) {
                int cur_x, cur_y;
                tie(cur_x, cur_y) = Q.front(); Q.pop();
                for (int k = 0; k < 4; k++) {
                    int x = cur_x + dx[k];
                    int y = cur_y + dy[k];
                    if (x < 0 || x >= N || y < 0 || y >= N) continue;
                    if (((table[x][y] == 'B') ^ (table[cur_x][cur_y] == 'B')) \
                        || vis[x][y] == true) continue;
                    vis[x][y] = true;
                    Q.push({ x, y });
                }
            }
        }
    }
    cout << cnt;

    return 0;
}