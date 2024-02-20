#include <bits/stdc++.h>
using namespace std;
int N, M;
int arr[10005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> arr[i];
    int cnt = 0;
    int st = 0;
    int en = 1;
    int sum = arr[0];
    for (; st < N; st++) {
        while (en < N && sum < M) {
            sum += arr[en++];
        }
        if (en == N && sum < M) break;
        if (sum == M) cnt++;
        sum -= arr[st];
    }
    cout << cnt;
    return 0;
}