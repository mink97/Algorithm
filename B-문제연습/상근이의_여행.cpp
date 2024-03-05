#include <bits/stdc++.h>
using namespace std;
// 최소 신장 트리
pair<int, int> edge[10005];
int parent[1005];
int ran[1005];
int T;

int find(int u) {
    if (parent[u] = u) return u;
    return parent[u] = find(parent[u]);
}

int merge(int a, int b) { // is_diff_group
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (ran[a] > ran[b]) swap(a, b);
    parent[a] = b;
    if (ran[a] == ran[b]) ran[b]++;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        // 초기화
        fill(edge, edge + M, make_pair(0, 0));
        fill(ran + 1, ran + N + 1, 0);
        for (int i = 1; i <= N; i++) {
            parent[i] = i;
        }
        // 입력값 받기
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            edge[i] = { u, v };
        }
        int cnt = 0;
        for (int i = 0; i < M; i++) {
            int u, v;
            tie(u, v) = edge[i];
            if (!merge(u, v)) continue;
            cnt++;
            if (cnt == N - 1) break;
        }
        cout << cnt << '\n';
    }

    return 0;
}