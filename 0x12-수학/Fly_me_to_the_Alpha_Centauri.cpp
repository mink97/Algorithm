#include <bits/stdc++.h>
using namespace std;
int T;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T--) {
        int x, y;
        cin >> x >> y;
        int dist = y - x;
        int n = (int)sqrt(dist);
        if (n * n == dist) cout << 2 * n - 1 << '\n';
        else if (dist >= n * n + 1 && dist <= n * n + n) cout << 2 * n << '\n';
        else cout << 2 * n + 1 << '\n';
    }

    return 0;
}