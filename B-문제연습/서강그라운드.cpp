#include <bits/stdc++.h>
using namespace std;
// 플로이드
int d[105][105];
int items[105];
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int V, lm, E;
    cin >> V >> lm >> E;
    for (int i = 1; i <= V; i++) // 아이템 개수
        cin >> items[i];
    for (int i = 1; i < V + 1; i++) // 테이블 초기화
        fill(d[i] + 1, d[i] + V + 1, INF);
    for (int i = 0; i < E; i++) { // 테이블 세팅
        int u, v, len;
        cin >> u >> v >> len;
        if (d[u][v] > len) {
            d[u][v] = len;
            d[v][u] = len;
        }
    }
    for (int i = 1; i <= V; i++) d[i][i] = 0;
    for (int k = 1; k <= V; k++) { // 플로이드 알고리즘
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                if (d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
    int MX = 0;
    for (int i = 1; i <= V; i++) {
        int tmp = 0;
        for (int j = 1; j <= V; j++) {
            if (d[i][j] <= lm) tmp += items[j];
        }
        MX = max(MX, tmp);
    }
    cout << MX;
    return 0;
}