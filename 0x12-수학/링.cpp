#include <bits/stdc++.h>
using namespace std;
int N;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int first;
    cin >> first;
    for (int i = 2; i <= N; i++) {
        int num;
        cin >> num;
        int GCD = gcd(first, num);
        cout << first / GCD << '/' << num / GCD << '\n';
    }
    return 0;
}