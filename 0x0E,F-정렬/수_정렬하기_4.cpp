#include <bits/stdc++.h>
using namespace std;
int arr[1000005];
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N, greater<int>());
    for (int i = 0; i < N; i++) {
        cout << arr[i] << '\n';
    }
    return 0;
}