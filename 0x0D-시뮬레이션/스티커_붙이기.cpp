#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int R, C;
int board[42][42];
int sticker[12][12];

void rotate() {
    int tmp[12][12];
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            tmp[i][j] = sticker[i][j];
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            sticker[j][i] = tmp[R - 1 - i][j];
        }
    }
    swap(R, C);
}

bool postable(int x, int y) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[x + i][y + j] == 1 && sticker[i][j] == 1)
                return false;
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (sticker[i][j])
                board[x + i][y + j] = 1;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K;
    while (K--) {
        cin >> R >> C;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> sticker[i][j];
            }
        }
        for (int rot = 0; rot < 4; rot++) {
            bool isPaste = false;
            for (int i = 0; i <= N - R; i++) {
                for (int j = 0; j <= M - C; j++) {
                    if (postable(i, j)) {
                        isPaste = true;
                        break;
                    }
                }
                if (isPaste) break;
            }
            if (isPaste) break;
            rotate();
        }
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cnt += board[i][j];
        }
    }
    cout << cnt;
    return 0;
}