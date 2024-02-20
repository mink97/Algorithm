#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[21][21];
int N, M, x, y, k;
pair<int, int> dx;
pair<int, int> dy;
pair<int, int> dz;

void move_1() {
    int tmp = dx.X;
    dx.X = dz.X;
    dz.X = dx.Y;
    dx.Y = dz.Y;
    dz.Y = tmp;
}

void move_2() {
    int tmp = dx.X;
    dx.X = dz.Y;
    dz.Y = dx.Y;
    dx.Y = dz.X;
    dz.X = tmp;
}

void move_3() {
    int tmp = dy.X;
    dy.X = dz.Y;
    dz.Y = dy.Y;
    dy.Y = dz.X;
    dz.X = tmp;
}

void move_4() {
    int tmp = dy.X;
    dy.X = dz.X;
    dz.X = dy.Y;
    dy.Y = dz.Y;
    dz.Y = tmp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> x >> y >> k;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    int curX = x, curY = y;
    while (k--) {
        int cmd;
        bool flag = false;
        cin >> cmd;
        switch (cmd) {

        case 1:
            if (curY + 1 < M) {
                flag = true;
                curY++;
                move_1();
            }
            break;

        case 2:
            if (curY - 1 >= 0) {
                flag = true;
                curY--;
                move_2();
            }
            break;

        case 3:
            if (curX - 1 >= 0) {
                flag = true;
                curX--;
                move_3();
            }
            break;

        case 4:
            if (curX + 1 < N) {
                flag = true;
                curX++;
                move_4();
            }
            break;
        default:
            break;
        }
        if (flag) {
            if (board[curX][curY] == 0) {
                board[curX][curY] = dz.Y;
            }
            else {
                dz.Y = board[curX][curY];
                board[curX][curY] = 0;
            }
            cout << dz.X << '\n';
        }
    }
    return 0;
}