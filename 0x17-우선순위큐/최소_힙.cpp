#include <bits/stdc++.h>
using namespace std;
int N;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    while (N--) {
        int n;
        cin >> n;
        if (n == 0) {
            if (pq.empty()) cout << 0 << '\n';
            else {
                int num = pq.top(); pq.pop();
                cout << num << '\n';
            }
        }
        else {
            pq.push(n);
        }
    }
}