#include <bits/stdc++.h>
using namespace std;
int N, M;
int arr[500005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    cin >> M;
    while (M--) {
        int tmp;
        cin >> tmp;
        cout << binary_search(arr, arr + N, tmp) << ' ';
    }
    return 0;
}