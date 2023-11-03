#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N);
    int max = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] * (N - i) > max) {
            max = arr[i] * (N - i);
        }
    }
    cout << max;
    return 0;
}