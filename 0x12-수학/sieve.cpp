#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int n) {
    vector<int> primes;
    vector<bool> state(n + 1, true);
    for (int i = 2; i * i <= n; i++) {
        if (!state[i]) continue;
        for (int j = i * i; j <= n; j += i) {
            state[j] = false;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (state[i]) primes.push_back(i);
    }
    return primes;
}