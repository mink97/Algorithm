#include <bits/stdc++.h>
using namespace std;
int dp[102][11];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < 10; i++) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][1];
        for (int j = 1; j < 9; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % (int)1e9;
        }
        dp[i][9] = dp[i - 1][8];
    }
    int ans = 0;
    for (int i = 1; i < 10; i++) {
        ans = (ans + dp[n][i]) % (int)1e9;
    }
    cout << ans;
    return 0;
}