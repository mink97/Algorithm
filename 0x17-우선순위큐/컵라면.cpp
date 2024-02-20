#include <bits/stdc++.h>
using namespace std;
int N;
priority_queue<int> pq;
vector<int> vec[200002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int solvedDay = N;
    for (int i = 0; i < N; i++) {
        int idx, v;
        cin >> idx >> v;
        vec[idx].push_back(v);
    }
    int ans = 0;
    for (int i = 200001; i != 0; i--) {
        for (auto elem : vec[i]) {
            pq.push(elem);
        }
        if (pq.empty()) continue;
        ans += pq.top();
        pq.pop();
    }
    cout << ans;
}