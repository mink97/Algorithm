#include <bits/stdc++.h>
using namespace std;

int N, M, K;

vector<vector<int>> rotate(vector<vector<int>>& sticker) {
    int x = sticker[0].size();
    int y = sticker.size();
    vector<vector<int>> ret(x, vector<int>(y, 0));
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            ret[i][j] = sticker[y - j - 1][i];
        }
    }
    return ret;
}

bool check(vector<vector<int>>& board, int x, int y, vector<vector<int>>& sticker) {
    for (int i = 0; i < sticker.size(); i++) {
        for (int j = 0; j < sticker[0].size(); j++) {
            if (sticker[i][j] == 0) continue;
            else if (board[x + i][y + j] == 1) return false;
        }
    }
    for (int i = 0; i < sticker.size(); i++) {
        for (int j = 0; j < sticker[0].size(); j++) {
            if (sticker[i][j] == 0) continue;
            else board[x + i][y + j] = 1;
        }
    }
    return true;
}

void insert(vector<vector<int>>& board, vector<vector<int>>& sticker) {
    vector<vector<int>> tmp;
    // tmp.assign(sticker.size(), vector<int>(sticker[0].size()));
    // copy(sticker.begin(), sticker.end(), tmp.begin());
    for (int n = 0; n < 4; n++) {
        if (n == 0) tmp = sticker;
        for (int i = 0; i <= N - static_cast<int>(tmp.size()); i++) {
            for (int j = 0; j <= M - static_cast<int>(tmp[0].size()); j++) {
                if (check(board, i, j, tmp) == true) {
                    return;
                }
            }
        }
        tmp = rotate(tmp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K;
    vector<vector<int>> board(N, vector<int>(M, 0));
    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        vector<vector<int>> sticker(x, vector<int>(y, 0));
        for (int a = 0; a < x; a++) {
            for (int b = 0; b < y; b++) {
                cin >> sticker[a][b];
            }
        }
        insert(board, sticker);
    }
    int cnt = N * M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!board[i][j]) cnt--;
        }
    }
    cout << cnt;
    return 0;
}