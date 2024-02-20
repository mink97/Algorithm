#include <bits/stdc++.h>
using namespace std;
int M, N;
vector<int> universe[102];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        pair<int, int> tmp[10002] = {};
        for (int j = 0; j < N; j++) {
            cin >> tmp[j].first;
            tmp[j].second = j;
        }
        sort(tmp, tmp + N);
        for (int j = 0; j < N; j++) {
            if (j != 0 && tmp[j].first == tmp[j - 1].first) {
                tmp[j].second = tmp[j - 1].second;
            }
            universe[i].push_back(tmp[j].second);
        }
    }
    sort(universe, universe + M);
    int cnt = 0;
    int idx = 0;
    while (idx < M) {
        int n = 0;
        while (idx + n < M && universe[idx] == universe[idx + n]) n++;
        cnt += (n * (n - 1) / 2);
        idx += n;
    }
    cout << cnt;
    return 0;
}