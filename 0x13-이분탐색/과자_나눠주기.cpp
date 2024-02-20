#include <bits/stdc++.h>
using namespace std;
int snack[1000005];
int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    long long sum = 0;
    for (int i = 0; i < M; i++) {
        cin >> snack[i];
        sum += snack[i];
    }
    if (sum < N) {
        cout << 0;
        return 0;
    }
    // sort(snack, snack + M);
    int st = 1;
    int en = *max_element(snack, snack + M);
    while (st < en) {
        int mid = (st + en + 1) / 2;
        int cnt = 0;
        for (int i = 0; i < M; i++) {
            cnt += snack[i] / mid;
        }
        if (cnt >= N) {
            st = mid;
        }
        else {
            en = mid - 1;
        }
    }
    cout << st;
    return 0;
}