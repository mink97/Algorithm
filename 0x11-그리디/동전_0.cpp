#include <bits/stdc++.h>
using namespace std;
int arr[12];
int N, K, cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    while (N--) {
        cnt += K / arr[N];
        K %= arr[N];
    }
    cout << cnt;
    return 0;
}