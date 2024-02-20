#include <bits/stdc++.h>
using namespace std;
int N, M;
int trees[1000005];

bool solve(int n) {
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += max(0, trees[i] - n);
    }
    return (sum >= M);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> trees[i];
    }
    int st = 0;
    int en = *max_element(trees, trees + N);
    while (st < en) {
        int mid = (st + en + 1) / 2;
        if (solve(mid)) st = mid;
        else en = mid - 1;
    }
    cout << st;
    return 0;
}