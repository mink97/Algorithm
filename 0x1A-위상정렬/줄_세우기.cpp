#include <bits/stdc++.h>
using namespace std;
vector<int> adj[32002];
int deg[32002];
int N, M;

void topological_sort() {
    queue<int> q;
    vector<int> result;

    for (int i = 1; i <= N; i++) {
        if (deg[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        result.push_back(cur);
        for (int nxt : adj[cur]) {
            deg[nxt]--;
            if (deg[nxt] == 0) q.push(nxt);
        }
    }
    for (int x : result) {
        cout << x << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        deg[v]++;
    }
    topological_sort();
    return 0;
}