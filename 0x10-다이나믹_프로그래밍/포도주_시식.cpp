#include <bits/stdc++.h>
using namespace std;
int arr[10005];
int dp[10005];
int n, mx;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    dp[0] = arr[0];
    dp[1] = arr[0] + arr[1];
    dp[2] = max({ arr[0] + arr[2], arr[1] + arr[2], arr[0] + arr[1] });
    for (int i = 3; i < n; i++) {
        dp[i] = max({ arr[i] + arr[i - 1] + dp[i - 3], arr[i] + dp[i - 2], dp[i - 1] });
    }
    cout << *max_element(dp, dp + n);
    return 0;
}