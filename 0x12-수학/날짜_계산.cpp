#include <bits/stdc++.h>
using namespace std;
int E, S, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> E >> S >> M;
    int a, b, c;
    a = E;
    b = S == 28 ? 0 : S;
    c = M == 19 ? 0 : M;
    int i = a;
    int lastYear = 15 * 28 * 19;
    for (; i <= lastYear; i += 15) {
        if (i % 28 == b) break;
    }
    for (; i <= lastYear; i += 420) {
        if (i % 19 == c) break;
    }
    cout << i;
    return 0;
}