#include <bits/stdc++.h>
using namespace std;

int gcd(int n, int m) {
    if (m == 0) return n;
    return gcd(m, n % m);
}

int lcm(int n, int m) {
    return n / gcd(n, m) * m;
}