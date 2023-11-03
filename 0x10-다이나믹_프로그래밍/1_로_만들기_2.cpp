#include <bits/stdc++.h>
using namespace std;
int D[1000005];
int pre[1000005];
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 2; i <= N; i++) {
        D[i] = D[i - 1] + 1;
        pre[i] = i - 1;
        if (i % 3 == 0 && D[i] > D[i / 3] + 1) {
            D[i] = D[i / 3] + 1;
            pre[i] = i / 3;
        }
        if (i % 2 == 0 && D[i] > D[i / 2] + 1) {
            D[i] = D[i / 2] + 1;
            pre[i] = i / 2;
        }
    }
    cout << D[N] << "\n";
    int i = N;
    while (i) {
        cout << i << " ";
        i = pre[i];
    }
    return 0;
}