#include <bits/stdc++.h>
using namespace std;
int arr[10005];
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    long long cnt = 0;
    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            cnt += upper_bound(arr + j + 1, arr + N, -(arr[i] + arr[j])) - lower_bound(arr + j + 1, arr + N, -(arr[i] + arr[j]));
        }
    }
    cout << cnt;
    return 0;
}