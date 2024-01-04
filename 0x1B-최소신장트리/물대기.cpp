#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N;
vector<pair<int, int>> adj[305];
bool chk[305];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int cost;
        cin >> cost;
        adj[N + 1].push_back({ cost, i });
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int tmp;
            cin >> tmp;
            if (i == j) continue;
            adj[i].push_back({ tmp, j });
        }
    }
    int cnt = 0, ans = 0;
    chk[N + 1] = 1;
    for (auto nxt : adj[N + 1]) {
        pq.push({ nxt.X, N + 1, nxt.Y });
    }
    while (cnt < N) {
        int cost, a, b;
        tie(cost, a, b) = pq.top(); pq.pop();
        if (chk[b]) continue;
        chk[b] = 1;
        cnt++;
        ans += cost;
        for (auto nxt : adj[b]) {
            if (!chk[nxt.Y])
                pq.push({ nxt.X, b, nxt.Y });
        }
    }
    cout << ans;
    return 0;
}