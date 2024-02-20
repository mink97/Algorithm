#include <bits/stdc++.h>
using namespace std;
int N;
int arr[52];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    int ans = 0;
    size_t pos = upper_bound(arr, arr + N, 0) - arr;
    size_t pos2 = upper_bound(arr, arr + N, 1) - arr;
    ans += (pos2 - pos);

    int i = 0;
    while (i + 1 < pos) {
        ans += arr[i] * arr[i + 1];
        i += 2;
    }
    if (i + 1 == pos) ans += arr[i];

    i = N - 1;
    while (i - 1 >= (int)pos2) {
        ans += arr[i] * arr[i - 1];
        i -= 2;
    }
    if (i == pos2) ans += arr[i];

    cout << ans;
    return 0;
}