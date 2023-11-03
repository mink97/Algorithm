#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll pow(ll a, ll b, ll c) {
    if (b == 1)
        return a;
    ll val = pow(a, b / 2, c);
    val = val * val % c;
    if (b % 2)
        return val * a % c;
    else
        return val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b, c;
    cin >> a >> b >> c;
    if (a > c) a %= c;
    cout << pow(a, b, c);

    return 0;
}