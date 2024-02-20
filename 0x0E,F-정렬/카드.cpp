#include <bits/stdc++.h>
using namespace std;

long long arr[100005];
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    arr[N] = 1ll << 62 + 1;
    sort(arr, arr + N);
    int cnt = 1;
    long long mxval = 0;
    int mxcnt = 0;
    for (int i = 1; i <= N; i++) {
        if (arr[i - 1] == arr[i]) cnt++;
        else {
            if (cnt > mxcnt) {
                mxcnt = cnt;
                mxval = arr[i - 1];
            }
            cnt = 1;
        }
    }
    cout << mxval;
    return 0;
}