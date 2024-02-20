#include <bits/stdc++.h>
using namespace std;

vector<bool> sieve(int n) {
    vector<bool> state(n + 1, true);
    for (int i = 2; i * i <= n; i++) {
        if (!state[i]) continue;
        for (int j = i * i; j <= n; j += i) {
            state[j] = false;
        }
    }
    return state;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<bool> state = sieve(247000);
    int n;
    cin >> n;
    while (n != 0) {
        int cnt = 0;
        for (int i = n + 1; i <= 2 * n; i++) {
            if (state[i]) cnt++;
        }
        cout << cnt << '\n';
        cin >> n;
    }

    return 0;
}