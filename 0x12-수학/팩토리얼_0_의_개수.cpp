#include <bits/stdc++.h>
using namespace std;
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int ans = 0;
    while (N) {
        ans += N / 5;
        N /= 5;
    }
    cout << ans;
    return 0;
}