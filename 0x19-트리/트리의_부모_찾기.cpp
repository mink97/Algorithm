#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100005];
int p[100005];
int N;

void dfs(int cur) {
    for (auto nxt : adj[cur]) {
        if (p[cur] == nxt) continue;
        p[nxt] = cur;
        dfs(nxt);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for (int n = 2; n <= N; n++) cout << p[n] << '\n';
    return 0;
}