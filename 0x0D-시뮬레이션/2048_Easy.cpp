#include <bits/stdc++.h>
using namespace std;
int N;
int board1[21][21];
int board2[21][21];

void rotate() {
    int tmp[21][21];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tmp[i][j] = board2[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board2[i][j] = tmp[N - 1 - j][i];
        }
    }
}

void tilt(int dir) {
    while (dir--) rotate();
    for (int i = 0; i < N; i++) {
        int tmp[21] = {};
        int idx = 0;
        for (int j = 0; j < N; j++) {
            if (board2[i][j] == 0) continue;
            if (tmp[idx] == 0) tmp[idx] = board2[i][j];
            else if (tmp[idx] == board2[i][j]) {
                tmp[idx++] *= 2;
            }
            else {
                tmp[++idx] = board2[i][j];
            }
        }
        for (int j = 0; j < N; j++) board2[i][j] = tmp[j];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board1[i][j];
        }
    }
    int mx = 0;
    for (int cs = 0; cs < 1 << (2 * 5); cs++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                board2[i][j] = board1[i][j];
            }
        }
        int tmp = cs;
        for (int i = 0; i < 5; i++) {
            int dir = tmp % 4;
            tmp /= 4;
            tilt(dir);
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                mx = max(mx, board2[i][j]);
            }
        }
    }
    cout << mx;
    return 0;
}