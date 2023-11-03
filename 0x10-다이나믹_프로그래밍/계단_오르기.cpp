#include <bits/stdc++.h>
using namespace std;
int stair[302];
int value[302];
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> stair[i];
    }
    value[1] = stair[1];
    value[2] = max(stair[1], stair[1] + stair[2]);
    for (int i = 3; i <= N; i++) {
        value[i] = max(value[i - 2] + stair[i], value[i - 3] + stair[i - 1] + stair[i]);
    }
    cout << value[N];
    return 0;
}