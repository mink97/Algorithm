#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll, ll> m;
ll N, P, Q;

ll func(ll n) {
    if (n == 0) return 1;
    if (n == 1) return 2;
    if (m.find(n) != m.end()) {
        return m[n];
    }
    m[n] = func(n / P) + func(n / Q);
    return m[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> P >> Q;
    cout << func(N);
    return 0;
}