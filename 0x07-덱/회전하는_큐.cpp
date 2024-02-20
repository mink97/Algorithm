#include <bits/stdc++.h>
using namespace std;
int N, M;
deque<int> dq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        dq.push_back(i);
    }
    while (M--) {
        int n;
        cin >> n;
        int idx = find(dq.begin(), dq.end(), n) - dq.begin();
        if (idx <= dq.size() / 2) {
            while (dq.front() != n) {
                dq.push_back(dq.front());
                dq.pop_front();
                ans++;
            }
        }
        else {
            while (dq.front() != n) {
                dq.push_front(dq.back());
                dq.pop_back();
                ans++;
            }
        }
        dq.pop_front();
    }
    cout << ans;
    return 0;
}