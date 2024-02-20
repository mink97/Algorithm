#include <bits/stdc++.h>
using namespace std;
int T;
int arr[102];
int comb[102];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (i == 0 || i == 1) comb[i] = 0;
            else comb[i] = 1;
        }
        long long ans = 0;
        do {
            int a = 0, b = 0;
            for (int i = 0; i < n; i++) {
                if (comb[i] == 0) {
                    if (a == 0) a = arr[i];
                    else {
                        b = arr[i];
                        break;
                    }
                }
            }
            ans += gcd(a, b);
        } while (next_permutation(comb, comb + n));
        cout << ans << '\n';
    }

    return 0;
}