#include <bits/stdc++.h>
using namespace std;
int N, L;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> L;
    priority_queue<pair<int, int>, \
        vector<pair<int, int>>, \
        greater<pair<int, int>>> pq;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        pq.push({ n, i });
        while (pq.top().second <= i - L) pq.pop();
        cout << pq.top().first << ' ';
    }
    // deque<pair<int, int>> dq;
    // for (int i = 0; i < N; i++) {
    //     int n;
    //     cin >> n;
    //     while (!dq.empty() && dq.back().second >= n) dq.pop_back();
    //     dq.push_back({ i, n });
    //     if (dq.front().first <= i - L) dq.pop_front();
    //     cout << dq.front().second << ' ';
    // }

    return 0;
}