#include <bits/stdc++.h>
using namespace std;

int dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
char table[12][12];
unordered_map<string, int> cnt; // string, cnt;
int N, M, K;

void dfs(int x, int y, string s) {
    cnt[s]++;
    if (s.size() == 5) return;
    for (int i = 0; i < 8; i++) {
        int cur_x = (x + dx[i] + N) % N;
        int cur_y = (y + dy[i] + M) % M;
        dfs(cur_x, cur_y, s + table[cur_x][cur_y]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> table[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            dfs(i, j, string(1, table[i][j]));
        }
    }
    for (int i = 0; i < K; i++) {
        string str;
        cin >> str;
        cout << cnt[str] << '\n';
    }
    return 0;
}