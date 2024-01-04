#include <bits/stdc++.h>
using namespace std;

// 크루스칼 알고리즘
int p[10005];
tuple<int, int, int> edge[100005];
int V, E;

int findParent(int x) {
    if (p[x] == x) return x;
    return p[x] = findParent(p[x]);
}

bool is_diff_group(int u, int v) {
    u = findParent(u);
    v = findParent(v);
    if (u == v) return false;
    if (u < v) p[v] = u;
    else p[u] = v;
    return true;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = { c, a, b };
    }
    sort(edge, edge + E);
    for (int i = 1; i <= V; i++) {
        p[i] = i;
    }
    int cnt = 0, ans = 0;
    for (int i = 0; i < E; i++) {
        int cost, a, b;
        tie(cost, a, b) = edge[i];
        if (!is_diff_group(a, b))   continue;
        ans += cost;
        cnt++;
        if (cnt == V - 1) break;
    }
    cout << ans;
}

/*
// 프림 알고리즘
#define X first
#define Y second

int V, E;
vector<pair<int, int>> adj[10005]; // {비용, 정점}
bool chk[10005];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ c, b });
        adj[b].push_back({ c, a }); // 양방향으로 추가
    }
    chk[1] = 1;
    for (auto nxt : adj[1]) {
        pq.push({ nxt.X, 1, nxt.Y });
    }
    int cnt = 0, ans = 0;
    while (cnt < V - 1) {
        int cost, a, b;
        tie(cost, a, b) = pq.top(); pq.pop();
        if (chk[b]) continue;
        ans += cost;
        chk[b] = 1; // 최소신장트리에 속함
        cnt++;
        for (auto nxt : adj[b]) {
            if (!chk[nxt.Y])
                pq.push({ nxt.X, b, nxt.Y });
        }
    }
    cout << ans;
    return 0;
}
*/