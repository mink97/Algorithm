#include <bits/stdc++.h>
using namespace std;
long long N, K;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    long long maxK = 0;
    int digit = 0;
    long long tmp = N;
    while (tmp) {
        digit++;
        tmp /= 10;
    }
    maxK += digit * (N);
    for (int i = 1; i < digit; i++) {
        maxK -= (pow(10, digit - i) - 1);
    }
    if (K > maxK) {
        cout << -1;
        return 0;
    }
    int i = 1;
    while (true) {
        long long check = i * pow(10, i - 1) * 9;
        if (K - check > 0) {
            K -= check;
            i++;
            continue;
        }
        long long target;
        long long pos;
        if (K % i == 0) {
            target = K / i + pow(10, i - 1) - 1;
            pos = 0;
        }
        else {
            target = K / i + pow(10, i - 1);
            pos = i - K % i;
        }
        long long ans = target / (long long)pow(10, pos) % 10;
        cout << ans;
        return 0;
    }
    return 0;
}