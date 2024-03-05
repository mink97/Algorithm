#include <bits/stdc++.h>
using namespace std;
// 그래프를 이용한 bfs, 좀 시간복잡도 길어도 그냥 인접행렬로 해보기
int adj[102][102];

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> adj[i][j];
        }
    }
    int ret[102][102] = {};
    for (int i = 1; i <= N; i++) {
        queue<int> q;
        bool vis[102] = {};
        for (int j = 1; j <= N; j++) {
            if (adj[i][j]) {
                q.push(j);
                vis[j] = 1;
            }
        }
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int j = 1; j <= N; j++) {
                if (vis[j]) continue;
                if (adj[cur][j]) {
                    q.push(j);
                    vis[j] = 1;
                }
            }
        }
        for (int j = 1; j <= N; j++) {
            cout << vis[j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}