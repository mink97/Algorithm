#include <bits/stdc++.h>
using namespace std;
int N, C;
int arr[200005];

bool solve(int dist) {
    int cnt = 1;
    int i = 0;
    while (i < N) {
        i = lower_bound(arr + i + 1, arr + N, arr[i] + dist) - arr;
        cnt++;
    }
    return (cnt > C);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    int st = 0;
    int en = 1000000001;
    while (st < en) {
        int mid = (st + en + 1) / 2;
        if (solve(mid)) st = mid;
        else en = mid - 1;
    }
    cout << st;
    return 0;
}