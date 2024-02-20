#include <bits/stdc++.h>
using namespace std;
long long arr[1005];
int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < M; i++) {
        swap(arr[0], *min_element(arr, arr + N));
        swap(arr[1], *min_element(arr + 1, arr + N));
        arr[0] += arr[1];
        arr[1] = arr[0];
    }
    cout << accumulate(arr, arr + N, 0ll);
    return 0;
}