#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    int a5 = 0, a2 = 0;

    int tmp = N;
    while (tmp) {
        a5 += tmp / 5;
        tmp /= 5;
    }
    tmp = M;
    while (tmp) {
        a5 -= tmp / 5;
        tmp /= 5;
    }
    tmp = N - M;
    while (tmp) {
        a5 -= tmp / 5;
        tmp /= 5;
    }

    tmp = N;
    while (tmp) {
        a2 += tmp / 2;
        tmp /= 2;
    }
    tmp = M;
    while (tmp) {
        a2 -= tmp / 2;
        tmp /= 2;
    }
    tmp = N - M;
    while (tmp) {
        a2 -= tmp / 2;
        tmp /= 2;
    }

    cout << min(a5, a2);
    return 0;
}