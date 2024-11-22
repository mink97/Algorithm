#include <bits/stdc++.h>
using namespace std;
int cache[1002][1002];
int N, K;

int choose(int times, int got) {
    if (times == N) return got == K;
    if (cache[times][got] != -1) return cache[times][got];
    return cache[times][got] = choose(times + 1, got) + choose(times + 1, got + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        fill(cache[i], cache[i] + K, -1);
    choose(0, 0);
    return 0;
}