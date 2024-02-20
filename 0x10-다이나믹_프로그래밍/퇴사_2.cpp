#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef long long ll;

pair<int, ll> P[1500002];
int N;
ll DP[1500002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> P[i].first >> P[i].second;
    }
    for (int i = N - 1; i >= 0; i--) {
        if (P[i].first + i > N) {
            DP[i] = DP[i + 1];
        }
        else {
            DP[i] = max(DP[i + 1], P[i].second + DP[i + P[i].first]);
        }
    }
    cout << DP[0];
    return 0;
}