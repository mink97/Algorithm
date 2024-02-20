#include <bits/stdc++.h>
using namespace std;
int T;
int arr[1000005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    int mx = 3;
    while (T--) {
        int n;
        cin >> n;
        if (n > mx) {
            for (int i = mx + 1; i <= n; i++) {
                arr[i] = ((long long)arr[i - 1] + arr[i - 2] + arr[i - 3]) % 1000000009;
            }
            mx = n;
        }
        cout << arr[n] << '\n';
    }

    return 0;
}