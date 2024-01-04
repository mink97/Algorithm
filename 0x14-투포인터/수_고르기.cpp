#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int st = 0, en = 0;
    int ans = INT_MAX;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    while (en != n) {
        int dif = arr[en] - arr[st];
        if (dif > m) {
            ans = min(ans, dif);
            st++;
        }
        else if (dif == m) {
            cout << m;
            return 0;
        }
        else {
            en++;
        }
    }
    cout << ans;
    return 0;
}