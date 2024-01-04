#include <bits/stdc++.h>
using namespace std;

int comb[1002][1002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        comb[i][0] = comb[i][i] = 1;
        for (int j = 1; j < i; j++) {
            if (j > k) break;
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % 10007;
        }
    }
    cout << comb[n][k];
    return 0;
}