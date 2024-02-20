#include <bits/stdc++.h>
using namespace std;
int N, K;
int cnt;

int sieve(int n) {
    vector<bool> state(N + 1, true);
    for (int i = 2; i <= N; i++) {
        if (!state[i]) continue;
        state[i] = false;
        cnt++;
        if (cnt == n) return i;
        for (int j = i * i; j <= N; j += i) {
            if (!state[j]) continue;
            cnt++;
            state[j] = false;
            if (cnt == n) return j;
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    cout << sieve(K);
    return 0;
}