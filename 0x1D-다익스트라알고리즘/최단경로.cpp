#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int INF = 0x3f3f3f3f;
// cost, dest
vector<pair<int, int>> adj[20005];
int V, E;
int d[20005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int st;
    cin >> V >> E >> st;
    fill(d + 1, d + V + 1, INF);
    while (E--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ w, v });
    }
    d[st] = 0;
    pq.push({ 0, st });
    while (!pq.empty()) {
        int cur_idx, w;
        tie(w, cur_idx) = pq.top(); pq.pop();
        if (d[cur_idx] != w) continue;
        for (pair<int, int> nxt : adj[cur_idx]) {
            if (d[nxt.Y] > d[cur_idx] + nxt.X) {
                d[nxt.Y] = d[cur_idx] + nxt.X;
                pq.push({ d[nxt.Y], nxt.Y });
            }
        }
    }
    for (int i = 1; i <= V; i++) {
        if (d[i] == INF) {
            cout << "INF" << '\n';
        }
        else {
            cout << d[i] << '\n';
        }
    }
    return 0;
}