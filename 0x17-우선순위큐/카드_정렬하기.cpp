#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    int ans = 0;
    cin >> N;
    while (N--) {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }
    while (pq.size() != 1) {
        int a, b;
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        ans += (a + b);
        pq.push(a + b);
    }
    cout << ans;
    return 0;
}