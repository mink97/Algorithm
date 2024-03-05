#include <bits/stdc++.h>
using namespace std;
// 최소신장트리 - 인접행렬로, 비용 long long으로, 크루스칼 알고리즘
int parent[1005];
int ran[1005];
int N;

int find(int n) {
    if (parent[n] == n) return n;
    return parent[n] = find(parent[n]); // 경로압축
}

bool is_diff_group(int u, int v) { // 다른 그룹이면 하나로 머지
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (ran[u] > ran[v]) swap(u, v); // union_by_rank
    parent[u] = v;
    if (ran[u] == ran[v]) ran[v]++;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        ran[i] = 1;
    }
    vector<tuple<int, int, int>> edge;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int cost;
            cin >> cost;
            if (j <= i || cost == 0) continue;
            edge.push_back({ cost, i, j });
        }
    }
    sort(edge.begin(), edge.end());
    int cnt = 0;
    long long total_cost = 0;
    for (int i = 0; i < edge.size(); i++) {
        int cost, u, v;
        tie(cost, u, v) = edge[i];
        if (!is_diff_group(u, v)) continue;
        cnt++;
        total_cost += cost;
        if (cnt == N - 1) break;
    }
    cout << total_cost;
    return 0;
}