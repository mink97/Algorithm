#include <bits/stdc++.h>
using namespace std;
long long P[102];
int T;
int mx = 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    P[1] = 1;
    P[2] = 1;
    P[3] = 1;
    P[4] = 2;
    P[5] = 2;
    while (T--) {
        int n;
        cin >> n;
        if (n > mx) {
            for (int i = mx; i < n; i++) {
                P[i + 1] = P[i] + P[i - 4];
            }
            mx = n;
        }
        cout << P[n] << '\n';
    }

    return 0;
}