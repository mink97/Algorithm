#include <bits/stdc++.h>
using namespace std;
int T;
int fibo[42][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    fibo[0][0] = 1;
    fibo[0][1] = 0;
    fibo[1][0] = 0;
    fibo[1][1] = 1;
    for (int i = 2; i <= 40; i++) {
        fibo[i][0] = fibo[i - 1][0] + fibo[i - 2][0];
        fibo[i][1] = fibo[i - 1][1] + fibo[i - 2][1];
    }
    while (T--) {
        int n;
        cin >> n;
        cout << fibo[n][0] << ' ' << fibo[n][1] << '\n';
    }

    return 0;
}