#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int INF = 0x3f3f3f3f;
vector<pair<int, int>> adj[1005];
int dis[1005];
int pre[1005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    fill(dis, dis + 1 + N, INF);
    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ w, v });
    }
    int st, des;
    cin >> st >> des;
    dis[st] = 0;
    pq.push({ 0, st });
    while (!pq.empty()) {
        int cur_idx, cur_dist;
        tie(cur_dist, cur_idx) = pq.top(); pq.pop();
        if (dis[cur_idx] != cur_dist) continue;
        for (auto nxt : adj[cur_idx]) {
            if (dis[nxt.Y] > dis[cur_idx] + nxt.X) {
                dis[nxt.Y] = dis[cur_idx] + nxt.X;
                pq.push({ dis[nxt.Y], nxt.Y });
                pre[nxt.Y] = cur_idx;
            }
        }
    }
    cout << dis[des] << '\n';
    vector<int> path;
    path.push_back(des);
    int p = des;
    while (pre[p] != st) {
        p = pre[p];
        path.push_back(p);
    }
    path.push_back(st);
    cout << path.size() << '\n';
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << ' ';
    }
    return 0;
}