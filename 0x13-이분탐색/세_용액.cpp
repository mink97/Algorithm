#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
ll liquid[5005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> liquid[i];
    }
    sort(liquid, liquid + N);
    ll a, b, c;
    ll minValue = 1e10 * 3;
    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            ll two = liquid[i] + liquid[j];
            int idx = lower_bound(liquid + j + 1, liquid + N, -two) - liquid;
            if (idx == N) idx--;
            else if (idx > j + 1 && abs(two + liquid[idx - 1]) < abs(two + liquid[idx])) idx--;
            if (abs(two + liquid[idx]) < minValue) {
                minValue = abs(two + liquid[idx]);
                a = liquid[i];
                b = liquid[j];
                c = liquid[idx];
            }
        }
    }
    cout << a << ' ' << b << ' ' << c;
    return 0;
}