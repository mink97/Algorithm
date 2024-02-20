#include <bits/stdc++.h>
using namespace std;
int P[1005];
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> P[i];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i / 2; j++) {
            P[i] = max(P[i], P[j] + P[i - j]);
        }
    }
    cout << P[N];
    return 0;
}