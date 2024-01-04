#include <bits/stdc++.h>
using namespace std;
int N, M;
int table[102][102];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    fill(&table[1][1], &table[N + 1][N], 0x3f3f3f3f);
    while (M--) {
        int a, b, cost;
        cin >> a >> b >> cost;
        table[a][b] = min(table[a][b], cost);
    }
    for (int i = 1; i <= N; i++) {
        for (int a = 1; a <= N; a++) {
            for (int b = 1; b <= N; b++) {
                if (a == b) {
                    table[a][b] = 0;
                    continue;
                }
                table[a][b] = min(table[a][b], table[a][i] + table[i][b]);
            }
        }
    }
    for (int a = 1; a <= N; a++) {
        for (int b = 1; b <= N; b++) {
            cout << (table[a][b] == 0x3f3f3f3f ? 0 : table[a][b]) << ' ';
        }
        cout << '\n';
    }
    return 0;
}