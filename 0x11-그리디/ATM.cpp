#include <bits/stdc++.h>
using namespace std;
int arr[1005];
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int curSum = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    for (int i = 0; i < N; i++) {
        curSum += arr[i];
        ans += curSum;
    }
    cout << ans;
    return 0;
}