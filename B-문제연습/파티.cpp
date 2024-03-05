#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
//다익스트라 이용
int d[1005][1005];
const int INF = 0x3f3f3f3f;
int N, M, P;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> P;
    for (int i = 1; i < N + 1; i++) {
        fill(d[i] + 1, d[i] + N + 1, INF);
    }
    for (int i = 0; i < M; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        if (d[u][v] > t) d[u][v] = t;
    }
    for (int i = 1; i <= N; i++) d[i][i] = 0;
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
    int MX = 0;
    for (int i = 1; i <= N; i++) {
        if (MX < d[i][P] + d[P][i]) MX = d[i][P] + d[P][i];
    }
    cout << MX;
    return 0;
}