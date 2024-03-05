#include <bits/stdc++.h>
using namespace std;
int sticker[2][100005];
int T;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        for (int i = 0; i < 2; i++)
            for (int j = 1; j <= N; j++)
                cin >> sticker[i][j];
        for (int i = 2; i <= N; i++) {
            sticker[0][i] += max(sticker[1][i - 1], sticker[1][i - 2]);
            sticker[1][i] += max(sticker[0][i - 1], sticker[0][i - 2]);
        }
        cout << max(sticker[0][N], sticker[1][N]) << '\n';
    }

    return 0;
}