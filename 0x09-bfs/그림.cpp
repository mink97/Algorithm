#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[502][502];
bool vis[502][502];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    int num = 0, mx = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (vis[i][j] || board[i][j] == 0) continue;
            num++;
            queue<pair<int, int> > Q;
            vis[i][j] = true;
            Q.push({ i, j });
            int area = 0;
            while (!Q.empty()) {
                area++;
                pair<int, int> cur = Q.front();
                Q.pop();
                for (int k = 0; k < 4; k++) {
                    int x = cur.X + dx[k];
                    int y = cur.Y + dy[k];
                    if (x < 0 || x >= N || y < 0 || y >= M) continue;
                    if (board[x][y] == 0 || vis[x][y]) continue;
                    Q.push({ x, y });
                    vis[x][y] = true;
                }
            }
            mx = mx > area ? mx : area;
        }
    }
    cout << num << "\n" << mx;
    return 0;
}