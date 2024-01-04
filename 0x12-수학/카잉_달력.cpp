#include <bits/stdc++.h>
using namespace std;

int gcd(int m, int n) {
    if (n == 0) return m;
    return gcd(n, m % n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cnt, m, n, x, y;
    cin >> cnt;
    while (cnt--) {
        cin >> m >> n >> x >> y;
        int lcm = m / gcd(m, n) * n;
        int i = x;
        if (y == n) y = 0;
        for (; i <= lcm; i += m) {
            if (i % n == y) break;
        }
        cout << (i > lcm ? -1 : i) << '\n';
    }
    return 0;
}