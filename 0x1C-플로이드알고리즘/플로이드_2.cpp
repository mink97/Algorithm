#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int N, M;
int table[105][105];
int nxt[105][105];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    fill(&table[1][1], &table[N][N], INF);
    while (M--) {
        int a, b, cost;
        cin >> a >> b >> cost;
        table[a][b] = min(table[a][b], cost);
        nxt[a][b] = b;
    }
    for (int i = 1; i <= N; i++) table[i][i] = 0;
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (table[i][j] > table[i][k] + table[k][j]) {
                    table[i][j] = table[i][k] + table[k][j];
                    nxt[i][j] = nxt[i][k]; // nxt[i][k]에는 무조건 값 존재
                }
            }
        }
    }
    for (int a = 1; a <= N; a++) {
        for (int b = 1; b <= N; b++) {
            cout << (table[a][b] == INF ? 0 : table[a][b]) << ' ';
        }
        cout << '\n';
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j || table[i][j] == INF) {
                cout << "0\n";
                continue;
            }
            vector<int> route;
            int st = i;
            while (st != j) {
                route.push_back(st);
                st = nxt[st][j];
            }
            route.push_back(j);
            cout << route.size() << ' ';
            for (int k = 0; k < route.size(); k++) {
                cout << route[k] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}