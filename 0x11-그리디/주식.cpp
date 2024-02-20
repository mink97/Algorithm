#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int arr[1000005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        ll profit = 0;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        int maxValue = arr[N - 1];
        for (int i = N - 2; i >= 0; i--) {
            if (arr[i] > maxValue) maxValue = arr[i];
            profit += maxValue - arr[i];
        }
        cout << profit << '\n';
    }

    return 0;
}