#include <bits/stdc++.h>
using namespace std;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
char field[14][8];
int vis[14][8];

int bfs(int i, int j) {
    int cnt = 0;
    queue<pair<int, int>> Q;
    Q.push({ i, j });
    vis[i][j] = 1;
    while (!Q.empty()) {
        int x, y;
        tie(x, y) = Q.front(); Q.pop();
        cnt++;
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (newX < 0 || newX >= 12 || newY < 0 || newY >= 6) continue;
            if (vis[newX][newY] == 1 || field[newX][newY] != field[x][y]) continue;
            Q.push({ newX, newY });
            vis[newX][newY] = 1;
        }
    }
    return cnt;
}

void gravity() {
    for (int i = 0; i < 6; i++) {
        char line[14] = {};
        int idx = 11;
        for (int j = 11; j >= 0; j--) {
            if (field[j][i] != '.') {
                line[idx--] = field[j][i];
            }
        }
        for (int j = 0; j < 12; j++) {
            if (j <= idx) {
                field[j][i] = '.';
            }
            else {
                field[j][i] = line[j];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> field[i][j];
        }
    }
    int ans = 0;
    while (true) {
        fill(&vis[0][0], &vis[13][8], 0);
        bool flag = false;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                if (vis[i][j] == 1 || field[i][j] == '.') continue;
                if (bfs(i, j) >= 4) {
                    if (!flag) flag = true;
                    char ch = field[i][j];
                    queue<pair<int, int>> Q;
                    Q.push({ i, j });
                    while (!Q.empty()) {
                        int x, y;
                        tie(x, y) = Q.front(); Q.pop();
                        field[x][y] = '.';
                        for (int k = 0; k < 4; k++) {
                            int newX = x + dx[k];
                            int newY = y + dy[k];
                            if (newX < 0 || newX >= 12 || newY < 0 || newY >= 6) continue;
                            if (field[newX][newY] != ch) continue;
                            Q.push({ newX, newY });
                        }
                    }
                }
            }
        }
        if (flag == true) {
            ans++;
            gravity();
        }
        else break;
    }
    cout << ans;
    return 0;
}