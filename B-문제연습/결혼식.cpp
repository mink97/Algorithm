#include <bits/stdc++.h>
using namespace std;
// 그래프를 이용한 bfs
vector<int> adj[502];
int depth[502];
int vis[502];
int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    fill(vis, vis + 502, -1);
    queue<int> q;
    q.push(1);
    vis[1] = 0;
    int cnt = 0;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto nxt : adj[cur]) {
            if (vis[nxt] != -1) continue;
            q.push(nxt);
            vis[nxt] = vis[cur] + 1;
            if (vis[nxt] <= 2) cnt++;
        }
    }
    cout << cnt;
    return 0;
}