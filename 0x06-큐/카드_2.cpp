#include <bits/stdc++.h>
using namespace std;
queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    while (q.size() != 1) {
        q.pop();
        int num = q.front();
        q.pop();
        q.push(num);
    }
    cout << q.front();
    return 0;
}