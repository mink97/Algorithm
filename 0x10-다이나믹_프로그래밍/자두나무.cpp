#include <bits/stdc++.h>
using namespace std;
int plum[1005];
int DP[32][1005];
int mx, T, W;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T >> W;
    for (int i = 1; i <= T; i++) {
        cin >> plum[i];
        DP[0][i] = plum[i] == 1 ? DP[0][i - 1] + 1 : DP[0][i - 1];
    }
    mx = DP[0][T];
    for (int i = 1; i <= W; i++) {
        for (int j = i; j <= T; j++) {
            DP[i][j] = max(DP[i][j - 1], DP[i - 1][j - 1]) + (i % 2 + 1 == plum[j]);
        }
        mx = max(mx, DP[i][T]);
    }
    cout << mx;
    return 0;
}