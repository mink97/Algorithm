#include <bits/stdc++.h>
using namespace std;
int N;
int D[1002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    D[1] = 1;
    D[2] = 2;
    for (int i = 3; i <= N; i++) {
        D[i] = (D[i - 1] + D[i - 2]) % 10007;
    }
    cout << D[N];

    return 0;
}