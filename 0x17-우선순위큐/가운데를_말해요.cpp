#include <bits/stdc++.h>
using namespace std;
priority_queue<int> pq1;
priority_queue<int, vector<int>, greater<int>> pq2;
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (i & 1) {
            pq1.push(num);
            num = pq1.top(); pq1.pop();
            pq2.push(num);
        }
        else {
            pq2.push(num);
            num = pq2.top(); pq2.pop();
            pq1.push(num);
        }
        cout << pq1.top() << '\n';
    }

    return 0;
}