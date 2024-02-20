#include <bits/stdc++.h>
using namespace std;
int N;

vector<int> sieve(int n) {
    vector<int> vec;
    vector<bool> state(n + 1, true);
    for (int i = 2; i * i <= n; i++) {
        if (!state[i]) continue;
        for (int j = i * i; j <= n; j += i) {
            state[j] = false;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (state[i]) vec.push_back(i);
    }
    return vec;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    vector<int> vec = sieve(N);
    int cnt = 0;
    int st = 0;
    int en = 0;
    int sum = 0;
    while (en < vec.size() || sum > N) {
        while (en < vec.size() && sum < N) {
            sum += vec[en];
            en++;
            if (sum == N) cnt++;
        }
        sum -= vec[st++];
        if (sum == N) cnt++;
    }
    cout << cnt;
    return 0;
}