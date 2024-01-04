#include <bits/stdc++.h>
using namespace std;

int arr[10005];
int n, k;

bool check(int num) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += arr[i] / num;
    }
    return cnt >= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    unsigned int st = 1;
    unsigned int en = INT_MAX;
    unsigned int mid;
    while (st < en) {
        mid = (st + en + 1) / 2;
        if (check(mid)) {
            st = mid;
        }
        else {
            en = mid - 1;
        }
    }
    cout << st;
    return 0;
}