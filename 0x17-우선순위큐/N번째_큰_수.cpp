#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        pq.push(num);
    }
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int num;
            cin >> num;
            if (pq.top() < num) {
                pq.pop();
                pq.push(num);
            }
        }
    }
    cout << pq.top();
}