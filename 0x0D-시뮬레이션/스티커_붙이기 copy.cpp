#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 40;
const int STICKER_MAX = 10;

int N, M, K;
int R, C;
int board[MAX][MAX];
int sticker[STICKER_MAX][STICKER_MAX];

void rotate(int cnt)
{
    int temp[STICKER_MAX][STICKER_MAX] = { 0, };

    for (int r = 0; r < (cnt % 2 ? C : R); r++) {
        for (int c = 0; c < (cnt % 2 ? R : C); c++) {
            temp[r][c] = sticker[r][c];
        }

        memset(sticker[r], 0, sizeof(sticker[r]));
    }

    for (int r = 0; r < (cnt % 2 ? C : R); r++) {
        for (int c = 0; c < (cnt % 2 ? R : C); c++) {
            sticker[c][(cnt % 2 ? C : R) - (1 + r)] = temp[r][c];
        }
    }
}

void putSticker(int i, int j, int cnt)
{
    for (int y = i; y < i + (cnt % 2 ? C : R); y++) {
        for (int x = j; x < j + (cnt % 2 ? R : C); x++) {
            if (board[y][x]) {
                continue;
            }

            board[y][x] = sticker[y - i][x - j];
        }
    }
}

void func(int cnt)
{
    if (cnt == 4) {
        return;
    }

    int row = cnt % 2 ? C : R;
    int col = cnt % 2 ? R : C;

    if (N < row || M < col) {
        rotate(cnt);
        func(cnt + 1);

        return;
    }

    bool flag = true;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            flag = true;

            if (row + i > N || col + j > M) {
                flag = false;
                break;
            }

            for (int r = 0; r < row; r++) {
                for (int c = 0; c < col; c++) {
                    if (sticker[r][c] && board[i + r][j + c]) {
                        flag = false;
                        break;
                    }
                }
                if (flag == false) {
                    break;
                }
            }
            if (flag) {
                putSticker(i, j, cnt);
                return;
            }
        }
    }

    if (flag == false) {
        rotate(cnt);
        func(cnt + 1);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;

    for (int k = 0; k < K; k++) {
        cin >> R >> C;

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                cin >> sticker[r][c];
            }
        }

        func(0);
    }

    int result = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            result += board[i][j];
        }
    }

    cout << result << "\n";

    return 0;
}