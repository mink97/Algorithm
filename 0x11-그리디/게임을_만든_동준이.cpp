#include <bits/stdc++.h>
using namespace std;
int N;
int arr[102];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int cnt = 0;
    for (int i = N - 2; i >= 0; i--) {
        if (arr[i + 1] <= arr[i]) {
            cnt += arr[i] - arr[i + 1] + 1;
            arr[i] = arr[i + 1] - 1;
        }
    }
    cout << cnt;
    return 0;
}