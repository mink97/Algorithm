#include <bits/stdc++.h>
using namespace std;
int n;
int arr[502][502];
int dp[502][502];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> arr[i][j];
        }
    }
    dp[1][1] = arr[1][1];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1) {
                dp[i][j] = dp[i - 1][j] + arr[i][j];
            }
            else if (j == i) {
                dp[i][j] = dp[i - 1][j - 1] + arr[i][j];
            }
            else {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
            }
        }
    }
    cout << *max_element(dp[n] + 1, dp[n] + n + 1);
    return 0;
}