#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int N, K;
pair<int, int> jewel[300003];
multiset<int> bag;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long ans = 0;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int weight, value;
        cin >> weight >> value;
        jewel[i] = { value, weight };
    }
    sort(jewel, jewel + N);
    for (int i = 0; i < K; i++) {
        int c;
        cin >> c;
        bag.insert(c);
    }
    for (int i = N - 1; i >= 0; i--) {
        if (bag.empty()) break;
        int wgh = jewel[i].Y;
        int val = jewel[i].X;
        // int wgh, val;
        // tie(val, wgh) = jewel[i];
        multiset<int>::iterator it = bag.lower_bound(wgh);
        if (it != bag.end()) {
            ans += jewel[i].X;
            bag.erase(it);
        }
    }
    cout << ans;
    return 0;
}