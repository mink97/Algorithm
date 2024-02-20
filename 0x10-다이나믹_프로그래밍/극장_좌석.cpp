#include <bits/stdc++.h>
using namespace std;
int dp[42];
// int arr[42];
int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int idx = 0;
    int cases = 1;
    for (int i = 0; i < M; i++) {
        int vip;
        cin >> vip;
        int len = vip - idx - 1;
        cases *= dp[len];
        idx = vip;
    }
    cases *= dp[N - idx];
    cout << cases;
    return 0;
}