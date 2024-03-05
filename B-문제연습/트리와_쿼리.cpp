#include <bits/stdc++.h>
using namespace std;
// 트리, bfs를 이용해서 채우면 될 듯
vector<int> adj[100005];
int p[100005];
int child_nodes[100005];
int N, R, Q;

void dfs(int root) {
    for (auto n : adj[root]) {
        if (p[root] == n) continue;
        p[n] = root;
        dfs(n);
        child_nodes[root] += child_nodes[n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> R >> Q;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    fill(child_nodes + 1, child_nodes + N + 1, 1);
    dfs(R);
    while (Q--) {
        int n;
        cin >> n;
        cout << child_nodes[n] << '\n';
    }
    return 0;
}