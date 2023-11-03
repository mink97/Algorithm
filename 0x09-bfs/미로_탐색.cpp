#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string board[102];
int vis[102][102] = { 0, };
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> board[i];
    queue<pair<int, int> > Q;
    Q.push({ 0, 0 });
    vis[0][0] = 1;
    while (!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (board[nx][ny] - '0' == 0 || vis[nx][ny] != 0) continue;
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            Q.push({ nx, ny });
        }
    }
    cout << vis[N - 1][M - 1];
    return 0;
}