#include <bits/stdc++.h>
using namespace std;
int n, m = 0, z = 0, p = 0;
int table[2200][2200];

void cnt(int n) {
    switch (n) {
    case 0:
        z++;
        break;
    case 1:
        p++;
        break;
    default:
        m++;
        break;
    }
}

void check(int sx, int sy, int ex, int ey) {
    int size = ex - sx;
    if (size == 1) {
        cnt(table[sx][sy]);
        return;
    }
    int value = table[sx][sy];
    for (int i = sx; i < ex; i++) {
        for (int j = sy; j < ey; j++) {
            if (table[i][j] != value) { // 9개로 쪼개기
                int tmp = size / 3;
                check(sx, sy, sx + tmp, sy + tmp);
                check(sx, sy + tmp, sx + tmp, sy + (tmp * 2));
                check(sx, sy + (tmp * 2), sx + tmp, sy + (tmp * 3));
                check(sx + tmp, sy, sx + (tmp * 2), sy + tmp);
                check(sx + tmp, sy + tmp, sx + (tmp * 2), sy + (tmp * 2));
                check(sx + tmp, sy + (tmp * 2), sx + (tmp * 2), sy + (tmp * 3));
                check(sx + (tmp * 2), sy, sx + (tmp * 3), sy + tmp);
                check(sx + (tmp * 2), sy + tmp, sx + (tmp * 3), sy + (tmp * 2));
                check(sx + (tmp * 2), sy + (tmp * 2), sx + (tmp * 3), sy + (tmp * 3));
                return;
            }
        }
    }
    cnt(value);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> table[i][j];
        }
    }
    check(0, 0, n, n);
    cout << m << '\n';
    cout << z << '\n';
    cout << p << '\n';
    return 0;
}