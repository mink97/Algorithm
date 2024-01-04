#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    int ans = n;
    if (k == 0 || k == n) {
        cout << 1;
        return 0;
    }
    for (int i = 1; i < k; i++) {
        ans *= n - i;
    }
    for (int i = 1; i <= k; i++) {
        ans /= i;
    }
    cout << ans;
    return 0;
}