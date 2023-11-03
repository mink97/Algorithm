#include <bits/stdc++.h>
using namespace std;
int D[1000005];
int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    cin >> D[1];
    for (int i = 2; i <= N; i++) {
        int n;
        cin >> n;
        D[i] = D[i - 1] + n;
    }
    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        cout << D[e] - D[s - 1] << "\n";
    }

    return 0;
}