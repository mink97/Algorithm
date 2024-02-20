#include <bits/stdc++.h>
using namespace std;
int M, N, K;
int table[102][102];
bool vis[102][102];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M >> N >> K;
    while (K--) {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        for (int i = sx; i < ex; i++) {
            for (int j = sy; j < ey; j++) {
                table[i][j] = 1;
            }
        }
    }
    queue<pair<int, int>> Q;
    vector<int> V;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (table[i][j] || vis[i][j]) continue;
            Q.push({ i, j });
            vis[i][j] = true;
            int area = 0;
            while (!Q.empty()) {
                int curX, curY;
                tie(curX, curY) = Q.front(); Q.pop();
                area++;
                for (int k = 0; k < 4; k++) {
                    int x = curX + dx[k];
                    int y = curY + dy[k];
                    if (x < 0 || x >= N || y < 0 || y >= M) continue;
                    if (vis[x][y] || table[x][y]) continue;
                    Q.push({ x, y });
                    vis[x][y] = true;
                }
            }
            V.push_back(area);
        }
    }
    cout << V.size() << '\n';
    sort(V.begin(), V.end());
    for (int i = 0; i < V.size(); i++) {
        cout << V[i] << ' ';
    }
    return 0;
}