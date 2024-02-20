#include <bits/stdc++.h>
using namespace std;
int N;
vector<pair<int, int>> V;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int s, e;
        cin >> s >> e;
        V.push_back({ s, 1 });
        V.push_back({ e, -1 });
    }
    sort(V.begin(), V.end());
    int ans = 0, cur = 0;
    int idx = 0;
    int tm = V[0].first;
    while (idx < 2 * N) {
        while (idx < 2 * N && V[idx].first == tm) {
            cur += V[idx].second;
            idx++;
        }
        ans = max(ans, cur);
        tm = V[idx].first;
    }
    cout << ans;
    return 0;
}