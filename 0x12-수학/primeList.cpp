#include <bits/stdc++.h>
using namespace std;

vector<int> primeList(int n) {
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        bool isPrime = true;
        for (int p : primes) {
            if (p * p > i) break;
            if (i % p == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) primes.push_back(i);
    }
    return primes;
}