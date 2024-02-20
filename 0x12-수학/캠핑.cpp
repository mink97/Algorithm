#include <bits/stdc++.h>
using namespace std;

int L, P, V;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int caseNum = 1;
    while (true) {
        cin >> L >> P >> V;
        if (L == 0 && P == 0 && V == 0) return 0;
        cout << "Case " << caseNum++ << ": ";
        int ans = 0;
        ans += L * (V / P);
        ans += V % P > L ? L : V % P;
        cout << ans << '\n';
    }

    return 0;
}