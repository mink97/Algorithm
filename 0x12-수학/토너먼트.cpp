#include <bits/stdc++.h>
using namespace std;
int N, a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> a >> b;
    if (a > b) swap(a, b);
    int cnt = 1;
    while (!(b - a == 1 && a / 2 != b / 2)) {
        cnt++;
        a = (a + a % 2) / 2;
        b = (b + b % 2) / 2;
    }
    cout << cnt;
    return 0;
}