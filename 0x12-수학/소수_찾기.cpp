#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, ans = 0;
    cin >> n;
    while (n--) {
        cin >> k;
        int i = 2;
        for (; i * i <= k; i++) {
            if (k % i == 0) break;
        }
        if (k != 1 && i * i > k) ans++;
    }
    cout << ans;
    return 0;
}