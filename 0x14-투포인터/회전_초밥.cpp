#include <bits/stdc++.h>
using namespace std;
int N, d, k, c;
int sushi[30002];
int types[3002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> d >> k >> c;
    for (int i = 0; i < N; i++) {
        cin >> sushi[i];
    }
    types[c] = 1;
    // c는 계속 true인 상태
    int cur = 1; // c로 인해 1가지는 무조건 먹음
    for (int i = 0; i < k; i++) {
        if (types[sushi[i]] == 0) {
            cur++;
        }
        types[sushi[i]]++;
    }
    int ans = cur;
    for (int st = 0; st < N; st++) {
        if (--types[sushi[st]] == 0) cur--;
        int en = (st + k) % N;
        if (types[sushi[en]]++ == 0) cur++;
        ans = max(ans, cur);
    }
    cout << ans;
    return 0;
}