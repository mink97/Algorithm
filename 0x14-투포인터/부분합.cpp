#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int n, s;
int st, en;
int min_len = 100005;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int sum = 0;
    for (; st < n; st++) {
        while (en < n && sum < s) {
            sum += arr[en++];
        }
        if (sum >= s) {
            int len = en - st;
            min_len = min(min_len, len);
        }
        else if (st == 0) {
            min_len = 0;
            break;
        }
        // cout << "st: " << st << ", en: " << en << "sum : " << sum << "\n";
        sum -= arr[st];
    }
    cout << min_len;
    return 0;
}