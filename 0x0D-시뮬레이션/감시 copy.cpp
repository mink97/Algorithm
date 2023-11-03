#include <bits/stdc++.h>
using namespace std;
#define X second.first
#define Y second.second
int N, M, ans;
int board[8][8];
void func(stack<pair<int, pair<int, int>>> STK, int num);

void func1(stack<pair<int, pair<int, int>>> STK, int num) {
    pair<int, pair<int, int>> cur = STK.top();
    STK.pop();
    // 위쪽 칠하기
    for (int i = cur.X - 1; i >= 0; i--) {
        if (board[i][cur.Y] == 6) break;
        else if (board[i][cur.Y] == 0) {
            board[i][cur.Y] = num;
        }
    }
    func(STK, num + 1);
    for (int i = cur.X - 1; i >= 0; i--) {
        if (board[i][cur.Y] == 6) break;
        else if (board[i][cur.Y] == num) {
            board[i][cur.Y] = 0;
        }
    }

    // 아래쪽 칠하기
    for (int i = cur.X + 1; i < N; i++) {
        if (board[i][cur.Y] == 6) break;
        else if (board[i][cur.Y] == 0) {
            board[i][cur.Y] = num;
        }
    }
    func(STK, num + 1);
    for (int i = cur.X + 1; i < N; i++) {
        if (board[i][cur.Y] == 6) break;
        else if (board[i][cur.Y] == num) {
            board[i][cur.Y] = 0;
        }
    }

    // 왼쪽 칠하기
    for (int i = cur.Y - 1; i >= 0; i--) {
        if (board[cur.X][i] == 6) break;
        else if (board[cur.X][i] == 0) {
            board[cur.X][i] = num;
        }
    }
    func(STK, num + 1);
    for (int i = cur.Y - 1; i >= 0; i--) {
        if (board[cur.X][i] == 6) break;
        else if (board[cur.X][i] == num) {
            board[cur.X][i] = 0;
        }
    }

    // 오른쪽 칠하기
    for (int i = cur.Y + 1; i < M; i++) {
        if (board[cur.X][i] == 6) break;
        else if (board[cur.X][i] == 0) {
            board[cur.X][i] = num;
        }
    }
    func(STK, num + 1);
    for (int i = cur.Y + 1; i < M; i++) {
        if (board[cur.X][i] == 6) break;
        else if (board[cur.X][i] == num) {
            board[cur.X][i] = 0;
        }
    }
}

void func2(stack<pair<int, pair<int, int>>> STK, int num) {
    pair<int, pair<int, int>> cur = STK.top();
    STK.pop();
    for (int i = cur.X - 1; i >= 0; i--) {
        if (board[i][cur.Y] == 6) break;
        else if (board[i][cur.Y] == 0) {
            board[i][cur.Y] = num;
        }
    }
    for (int i = cur.X + 1; i < N; i++) {
        if (board[i][cur.Y] == 6) break;
        else if (board[i][cur.Y] == 0) {
            board[i][cur.Y] = num;
        }
    }
    func(STK, num + 1);
    for (int i = cur.X - 1; i >= 0; i--) {
        if (board[i][cur.Y] == 6) break;
        else if (board[i][cur.Y] == num) {
            board[i][cur.Y] = 0;
        }
    }
    for (int i = cur.X + 1; i < N; i++) {
        if (board[i][cur.Y] == 6) break;
        else if (board[i][cur.Y] == num) {
            board[i][cur.Y] = 0;
        }
    }

    for (int i = cur.Y - 1; i >= 0; i--) {
        if (board[cur.X][i] == 6) break;
        else if (board[cur.X][i] == 0) {
            board[cur.X][i] = num;
        }
    }
    for (int i = cur.Y + 1; i < M; i++) {
        if (board[cur.X][i] == 6) break;
        else if (board[cur.X][i] == 0) {
            board[cur.X][i] = num;
        }
    }
    func(STK, num + 1);
    for (int i = cur.Y - 1; i >= 0; i--) {
        if (board[cur.X][i] == 6) break;
        else if (board[cur.X][i] == num) {
            board[cur.X][i] = 0;
        }
    }
    for (int i = cur.Y + 1; i < M; i++) {
        if (board[cur.X][i] == 6) break;
        else if (board[cur.X][i] == num) {
            board[cur.X][i] = 0;
        }
    }
}

void func3(stack<pair<int, pair<int, int>>> STK, int num) {
    pair<int, pair<int, int>> cur = STK.top();
    STK.pop();
    // 상 우
    for (int i = cur.X - 1; i >= 0; i--) {
        if (board[i][cur.Y] == 6) break;
        else if (board[i][cur.Y] == 0) {
            board[i][cur.Y] = num;
        }
    }
    for (int i = cur.Y + 1; i < M; i++) {
        if (board[cur.X][i] == 6) break;
        else if (board[cur.X][i] == 0) {
            board[cur.X][i] = num;
        }
    }
    func(STK, num + 1);
    for (int i = cur.X - 1; i >= 0; i--) {
        if (board[i][cur.Y] == 6) break;
        else if (board[i][cur.Y] == num) {
            board[i][cur.Y] = 0;
        }
    }
    for (int i = cur.Y + 1; i < M; i++) {
        if (board[cur.X][i] == 6) break;
        else if (board[cur.X][i] == num) {
            board[cur.X][i] = 0;
        }
    }

    // 하 좌
    for (int i = cur.X + 1; i < N; i++) {
        if (board[i][cur.Y] == 6) break;
        else if (board[i][cur.Y] == 0) {
            board[i][cur.Y] = num;
        }
    }
    for (int i = cur.Y - 1; i >= 0; i--) {
        if (board[cur.X][i] == 6) break;
        else if (board[cur.X][i] == 0) {
            board[cur.X][i] = num;
        }
    }
    func(STK, num + 1);
    for (int i = cur.X + 1; i < N; i++) {
        if (board[i][cur.Y] == 6) break;
        else if (board[i][cur.Y] == num) {
            board[i][cur.Y] = 0;
        }
    }
    for (int i = cur.Y - 1; i >= 0; i--) {
        if (board[cur.X][i] == 6) break;
        else if (board[cur.X][i] == num) {
            board[cur.X][i] = 0;
        }
    }

    // 상 좌
    for (int i = cur.X - 1; i >= 0; i--) {
        if (board[i][cur.Y] == 6) break;
        else if (board[i][cur.Y] == 0) {
            board[i][cur.Y] = num;
        }
    }
    for (int i = cur.Y - 1; i >= 0; i--) {
        if (board[cur.X][i] == 6) break;
        else if (board[cur.X][i] == 0) {
            board[cur.X][i] = num;
        }
    }
    func(STK, num + 1);
    for (int i = cur.X - 1; i >= 0; i--) {
        if (board[i][cur.Y] == 6) break;
        else if (board[i][cur.Y] == num) {
            board[i][cur.Y] = 0;
        }
    }
    for (int i = cur.Y - 1; i >= 0; i--) {
        if (board[cur.X][i] == 6) break;
        else if (board[cur.X][i] == num) {
            board[cur.X][i] = 0;
        }
    }

    // 하 우
    for (int i = cur.X + 1; i < N; i++) {
        if (board[i][cur.Y] == 6) break;
        else if (board[i][cur.Y] == 0) {
            board[i][cur.Y] = num;
        }
    }
    for (int i = cur.Y + 1; i < M; i++) {
        if (board[cur.X][i] == 6) break;
        else if (board[cur.X][i] == 0) {
            board[cur.X][i] = num;
        }
    }
    func(STK, num + 1);
    for (int i = cur.X + 1; i < N; i++) {
        if (board[i][cur.Y] == 6) break;
        else if (board[i][cur.Y] == num) {
            board[i][cur.Y] = 0;
        }
    }
    for (int i = cur.Y + 1; i < M; i++) {
        if (board[cur.X][i] == 6) break;
        else if (board[cur.X][i] == num) {
            board[cur.X][i] = 0;
        }
    }
}

void func4(stack<pair<int, pair<int, int>>> STK, int num) {
    pair<int, pair<int, int>> cur = STK.top();
    STK.pop();
    // 좌 상 우
    for (int i = cur.Y - 1; i >= 0; i--) {
        if (board[cur.X][i] == 6) break;
        else if (board[cur.X][i] == 0) {
            board[cur.X][i] = num;
        }
    }
    for (int i = cur.X - 1; i >= 0; i--) {
        if (board[i][cur.Y] == 6) break;
        else if (board[i][cur.Y] == 0) {
            board[i][cur.Y] = num;
        }
    }
    for (int i = cur.Y + 1; i < M; i++) {
        if (board[cur.X][i] == 6) break;
        else if (board[cur.X][i] == 0) {
            board[cur.X][i] = num;
        }
    }
    func(STK, num + 1);
    for (int i = cur.Y - 1; i >= 0; i--) {
        if (board[cur.X][i] == 6) break;
        else if (board[cur.X][i] == num) {
            board[cur.X][i] = 0;
        }
    }
    for (int i = cur.X - 1; i >= 0; i--) {
        if (board[i][cur.Y] == 6) break;
        else if (board[i][cur.Y] == num) {
            board[i][cur.Y] = 0;
        }
    }
    for (int i = cur.Y + 1; i < M; i++) {
        if (board[cur.X][i] == 6) break;
        else if (board[cur.X][i] == num) {
            board[cur.X][i] = 0;
        }
    }

    // 상 하 좌
    for (int i = cur.X - 1; i >= 0; i--) {
        if (board[i][cur.Y] == 6) break;
        else if (board[i][cur.Y] == 0) {
            board[i][cur.Y] = num;
        }
    }
    for (int i = cur.X + 1; i < N; i++) {
        if (board[i][cur.Y] == 6) break;
        else if (board[i][cur.Y] == 0) {
            board[i][cur.Y] = num;
        }
    }
    for (int i = cur.Y - 1; i >= 0; i--) {
        if (board[cur.X][i] == 6) break;
        else if (board[cur.X][i] == 0) {
            board[cur.X][i] = num;
        }
    }
    func(STK, num + 1);
    for (int i = cur.X - 1; i >= 0; i--) {
        if (board[i][cur.Y] == 6) break;
        else if (board[i][cur.Y] == num) {
            board[i][cur.Y] = 0;
        }
    }
    for (int i = cur.X + 1; i < N; i++) {
        if (board[i][cur.Y] == 6) break;
        else if (board[i][cur.Y] == num) {
            board[i][cur.Y] = 0;
        }
    }
    for (int i = cur.Y - 1; i >= 0; i--) {
        if (board[cur.X][i] == 6) break;
        else if (board[cur.X][i] == num) {
            board[cur.X][i] = 0;
        }
    }

    // 좌 하 우
    for (int i = cur.Y - 1; i >= 0; i--) {
        if (board[cur.X][i] == 6) break;
        else if (board[cur.X][i] == 0) {
            board[cur.X][i] = num;
        }
    }
    for (int i = cur.X + 1; i < N; i++) {
        if (board[i][cur.Y] == 6) break;
        else if (board[i][cur.Y] == 0) {
            board[i][cur.Y] = num;
        }
    }
    for (int i = cur.Y + 1; i < M; i++) {
        if (board[cur.X][i] == 6) break;
        else if (board[cur.X][i] == 0) {
            board[cur.X][i] = num;
        }
    }
    func(STK, num + 1);
    for (int i = cur.Y - 1; i >= 0; i--) {
        if (board[cur.X][i] == 6) break;
        else if (board[cur.X][i] == num) {
            board[cur.X][i] = 0;
        }
    }
    for (int i = cur.X + 1; i < N; i++) {
        if (board[i][cur.Y] == 6) break;
        else if (board[i][cur.Y] == num) {
            board[i][cur.Y] = 0;
        }
    }
    for (int i = cur.Y + 1; i < M; i++) {
        if (board[cur.X][i] == 6) break;
        else if (board[cur.X][i] == num) {
            board[cur.X][i] = 0;
        }
    }

    // 하 우 상
    for (int i = cur.X + 1; i < N; i++) {
        if (board[i][cur.Y] == 6) break;
        else if (board[i][cur.Y] == 0) {
            board[i][cur.Y] = num;
        }
    }
    for (int i = cur.Y + 1; i < M; i++) {
        if (board[cur.X][i] == 6) break;
        else if (board[cur.X][i] == 0) {
            board[cur.X][i] = num;
        }
    }
    for (int i = cur.X - 1; i >= 0; i--) {
        if (board[i][cur.Y] == 6) break;
        else if (board[i][cur.Y] == 0) {
            board[i][cur.Y] = num;
        }
    }
    func(STK, num + 1);
    for (int i = cur.X + 1; i < N; i++) {
        if (board[i][cur.Y] == 6) break;
        else if (board[i][cur.Y] == num) {
            board[i][cur.Y] = 0;
        }
    }
    for (int i = cur.Y + 1; i < M; i++) {
        if (board[cur.X][i] == 6) break;
        else if (board[cur.X][i] == num) {
            board[cur.X][i] = 0;
        }
    }
    for (int i = cur.X - 1; i >= 0; i--) {
        if (board[i][cur.Y] == 6) break;
        else if (board[i][cur.Y] == num) {
            board[i][cur.Y] = 0;
        }
    }
}

void func5(stack<pair<int, pair<int, int>>> STK, int num) {
    pair<int, pair<int, int>> cur = STK.top();
    STK.pop();
    // 하 좌 상 우
    for (int i = cur.X + 1; i < N; i++) {
        if (board[i][cur.Y] == 6) break;
        else if (board[i][cur.Y] == 0) {
            board[i][cur.Y] = num;
        }
    }
    for (int i = cur.Y - 1; i >= 0; i--) {
        if (board[cur.X][i] == 6) break;
        else if (board[cur.X][i] == 0) {
            board[cur.X][i] = num;
        }
    }
    for (int i = cur.X - 1; i >= 0; i--) {
        if (board[i][cur.Y] == 6) break;
        else if (board[i][cur.Y] == 0) {
            board[i][cur.Y] = num;
        }
    }
    for (int i = cur.Y + 1; i < M; i++) {
        if (board[cur.X][i] == 6) break;
        else if (board[cur.X][i] == 0) {
            board[cur.X][i] = num;
        }
    }
    func(STK, num + 1);
    for (int i = cur.X + 1; i < N; i++) {
        if (board[i][cur.Y] == 6) break;
        else if (board[i][cur.Y] == num) {
            board[i][cur.Y] = 0;
        }
    }
    for (int i = cur.Y - 1; i >= 0; i--) {
        if (board[cur.X][i] == 6) break;
        else if (board[cur.X][i] == num) {
            board[cur.X][i] = 0;
        }
    }
    for (int i = cur.X - 1; i >= 0; i--) {
        if (board[i][cur.Y] == 6) break;
        else if (board[i][cur.Y] == num) {
            board[i][cur.Y] = 0;
        }
    }
    for (int i = cur.Y + 1; i < M; i++) {
        if (board[cur.X][i] == 6) break;
        else if (board[cur.X][i] == num) {
            board[cur.X][i] = 0;
        }
    }
}

void func(stack<pair<int, pair<int, int>>> STK, int num) {
    if (STK.empty()) {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!board[i][j]) cnt++;
            }
        }
        ans = min(cnt, ans);
        return;
    }
    if (STK.top().first == 1)
        func1(STK, num);
    else if (STK.top().first == 2)
        func2(STK, num);
    else if (STK.top().first == 3)
        func3(STK, num);
    else if (STK.top().first == 4)
        func4(STK, num);
    else if (STK.top().first == 5)
        func5(STK, num);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    ans = 64;
    stack<pair<int, pair<int, int>>> STK;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] >= 1 && board[i][j] <= 5)
                STK.push({ board[i][j], {i, j} });
        }
    }
    func(STK, 7);
    cout << ans;
    return 0;
}