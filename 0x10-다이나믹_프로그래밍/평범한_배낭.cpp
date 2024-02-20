#include <bits/stdc++.h>
using namespace std;
int DP[100005];
int N, K;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int weight, value;
        cin >> weight >> value;
        for (int j = K; j >= weight; j--) {
            DP[j] = max(DP[j - weight] + value, DP[j]);
        }
    }
    cout << DP[K];
    return 0;
}