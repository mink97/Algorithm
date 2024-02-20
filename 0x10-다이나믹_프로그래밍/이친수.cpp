#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt[92];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cnt[1] = 1;
    cnt[2] = 1;
    for (int i = 3; i <= n; i++) {
        cnt[i] = cnt[i - 1] + cnt[i - 2];
    }
    cout << cnt[n];
    return 0;
}