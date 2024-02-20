#include <bits/stdc++.h>
using namespace std;
int num[11];

void increase(int pos) {
    if (pos == 10) {
        num[pos] = -1;
        return;
    }
    if (num[pos] == 10) {
        num[pos] = pos;
    }
    else if (num[pos] + 1 < num[pos + 1]) {
        num[pos]++;
    }
    else {
        num[pos] = pos;
        increase(pos + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    fill(num, num + 11, 10);
    cin >> n;
    int cnt = 0;
    num[0] = 0;
    while (cnt != n) {
        increase(0);
        if (num[10] != 10) {
            cout << -1;
            return 0;
        }
        cnt++;
    }
    for (int i = 9; i >= 0; i--) {
        if (num[i] == 10) continue;
        cout << num[i];
    }
    return 0;
}