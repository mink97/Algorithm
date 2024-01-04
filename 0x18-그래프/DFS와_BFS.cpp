#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1005];
int N, M, V;
bool vis[1005];

void DFS(int cur) {
    vis[cur] = true;
    cout << cur << ' ';
    for (auto nxt : adj[cur]) {
        if (vis[nxt]) continue;
        DFS(nxt);
    }
}

void BFS() {
    queue<int> q;
    bool vis[1005];
    fill(vis, vis + N + 1, false);
    q.push(V);
    vis[V] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for (auto nxt : adj[cur]) {
            if (vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = true;
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> V;
    while (M--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= N; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    // DFS
    DFS(V);
    cout << '\n';
    // BFS
    BFS();

    return 0;
}