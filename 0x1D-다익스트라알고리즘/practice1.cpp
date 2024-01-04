#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

vector<pair<int, int>> adj[20005];
const int INF = 0x3f3f3f3f;
bool fix[20005];
int d[20005];
int v = 10;

void dijkstra_naive(int st) {
    fill(d, d + v + 1, INF);
    d[st] = 0;
    while (true) {
        int idx = -1;
        for (int i = 1; i <= v; i++) {
            if (fix[i]) continue;
            if (idx = -1) idx = i;
            else if (d[i] < d[idx]) idx = i;
        }
        if (idx == -1 || d[idx] == INF)
            break;
        fix[idx] = 1;
        for (auto nxt : adj[idx])
            d[nxt.Y] = min(d[nxt.Y], d[idx] + nxt.X);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    return 0;
}