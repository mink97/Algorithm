#include <bits/stdc++.h>
using namespace std;

int table[102][102];
bool vis[102][102];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int N;

int getAreaCnt(int height) {
    fill(&vis[0][0], &vis[N - 1][N], false);
    int cnt = 0;
    queue<pair<int, int>> Q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (table[i][j] <= height || vis[i][j] == true) continue;
            Q.push({ i, j });
            vis[i][j] = true;
            cnt++;
            while (!Q.empty()) {
                int curX, curY;
                tie(curX, curY) = Q.front(); Q.pop();
                for (int k = 0; k < 4; k++) {
                    int x = curX + dx[k];
                    int y = curY + dy[k];
                    if (x < 0 || x >= N || y < 0 || y >= N) continue;
                    if (table[x][y] <= height || vis[x][y] == true) continue;
                    Q.push({ x, y });
                    vis[x][y] = true;
                }
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int maxheight = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> table[i][j];
            maxheight = max(maxheight, table[i][j]);
        }
    }
    int maxcnt = 0;
    for (int i = 0; i < maxheight; i++) {
        maxcnt = max(maxcnt, getAreaCnt(i));
    }
    cout << maxcnt;
    return 0;
}