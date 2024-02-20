#include <bits/stdc++.h>
using namespace std;
int T, N, M;
int Aarr[20002];
int Barr[20002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            cin >> Aarr[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> Barr[i];
        }
        sort(Barr, Barr + M);
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            cnt += lower_bound(Barr, Barr + M, Aarr[i]) - Barr;
        }
        cout << cnt << '\n';
    }

    return 0;
}