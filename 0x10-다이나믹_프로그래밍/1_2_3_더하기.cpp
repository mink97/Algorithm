#include <bits/stdc++.h>
using namespace std;
int d[12];
int T;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    int mx = 4;
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    d[4] = 7;
    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        if (n > mx) {
            for (int j = mx; j <= n; j++)
                d[j] = d[j - 1] + d[j - 2] + d[j - 3];
            mx = n;
        }
        cout << d[n] << "\n";
    }
    return 0;
}