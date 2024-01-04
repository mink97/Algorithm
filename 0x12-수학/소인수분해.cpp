#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int i = 2;
    while (i * i <= n) {
        while (n % i == 0) {
            cout << i << '\n';
            n /= i;
        }
        i++;
    }
    if (n != 1) cout << n << '\n';
    return 0;
}