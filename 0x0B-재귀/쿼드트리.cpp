#include <bits/stdc++.h>
using namespace std;
int N;
char table[80][80];

bool check(int x, int y, int n) {
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (table[i][j] != table[x][y])
                return false;
        }
    }
    return true;
}

void quadTree(int x, int y, int n) {
    if (check(x, y, n)) {
        cout << table[x][y];
        return;
    }
    cout << '(';
    quadTree(x, y, n / 2);
    quadTree(x, y + n / 2, n / 2);
    quadTree(x + n / 2, y, n / 2);
    quadTree(x + n / 2, y + n / 2, n / 2);
    cout << ')';
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
    quadTree(0, 0, N);
    return 0;
}