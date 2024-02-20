#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fibo[92];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    fibo[1] = 1;
    for (int i = 2; i <= n; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
    cout << fibo[n];
    return 0;
}