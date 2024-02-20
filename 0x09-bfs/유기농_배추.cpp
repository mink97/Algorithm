#include <bits/stdc++.h>
using namespace std;
int T;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T--) {
        int M, N, K;
        cin >> M >> N >> K;
        int table[52][52] = { 0, };
        bool vis[52][52] = { 0, };
        while (K--) {
            int x, y;
            cin >> x >> y;
            table[x][y] = 1;
        }
        int cnt = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (table[i][j] == 0 || vis[i][j] == true) continue;
                cnt++;
                queue<pair<int, int>> Q;
                Q.push({ i, j });
                vis[i][j] = true;
                while (!Q.empty()) {
                    int cur_x, cur_y;
                    tie(cur_x, cur_y) = Q.front(); Q.pop();
                    for (int k = 0; k < 4; k++) {
                        int x = cur_x + dx[k];
                        int y = cur_y + dy[k];
                        if (x < 0 || x >= M || y < 0 || y >= N) continue;
                        if (vis[x][y] == true || table[x][y] == 0) continue;
                        Q.push({ x, y });
                        vis[x][y] = true;
                    }
                }
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}