#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
//다익스트라 이용
vector<pair<int, int>> adj[1005]; // 비용, 정점
const int INF = 0x3f3f3f3f;
int N, M, P;
int d[1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> P;
    for (int i = 0; i < M; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        adj[u].push_back({ t, v });
    }
    fill(d + 1, d + N + 1, INF);
    d[P] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({ 0, P });
    while (!pq.empty()) {
        int tm, cur;
        tie(tm, cur) = pq.top(); pq.pop();
        if (d[cur] != tm) continue;
        for (auto nxt : adj[cur]) {
            if (d[nxt.Y] > tm + nxt.X) {
                d[nxt.Y] = tm + nxt.X;
                pq.push({ d[nxt.Y], nxt.Y });
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << d[i] << ' ';
    }
    return 0;
}