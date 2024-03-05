#include <bits/stdc++.h>
using namespace std;
int table[1030][1030];
int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> table[i][j];
        }
    }
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            table[i][j] = table[i][j] + table[i][j - 1];
    for (int j = 1; j <= N; j++)
        for (int i = 1; i <= N; i++)
            table[i][j] = table[i][j] + table[i - 1][j];
    while (M--) {
        int ax, ay, bx, by;
        cin >> ax >> ay >> bx >> by;
        int areaA, areaB, areaC, areaD;
        areaA = table[bx][by];
        areaB = table[ax - 1][by];
        areaC = table[bx][ay - 1];
        areaD = table[ax - 1][ay - 1];
        int ans = areaA - areaB - areaC + areaD;
        cout << ans << '\n';
    }
    return 0;
}