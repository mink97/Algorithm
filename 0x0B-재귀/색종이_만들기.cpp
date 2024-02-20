#include <bits/stdc++.h>
using namespace std;
int N;
int table[130][130];
int W, B;

void check(int sa, int sb, int ea, int eb) {
    int value = table[sa][sb];
    int mid = (ea - sa) / 2;
    if (mid == 0) {
        if (value) B++;
        else W++;
        return;
    }
    for (int i = sa; i < ea; i++) {
        for (int j = sb; j < eb; j++) {
            if (table[i][j] != value) {
                check(sa, sb, sa + mid, sb + mid);
                check(sa + mid, sb, ea, sb + mid);
                check(sa, sb + mid, sa + mid, eb);
                check(sa + mid, sb + mid, ea, eb);
                return;
            }
        }
    }
    if (value) B++;
    else W++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> table[i][j];
        }
    }
    check(0, 0, N, N);
    cout << W << '\n';
    cout << B << '\n';
    return 0;
}