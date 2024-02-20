#include <bits/stdc++.h>
using namespace std;
int table[302][302];
int dis[302][302];
int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    while (N--) {
        int L;
        cin >> L;
        fill(&table[0][0], &table[L - 1][L], 0);
        fill(&dis[0][0], &dis[L - 1][L], -1);
        queue<pair<int, int>> Q;
        int posX, posY;
        int desX, desY;
        cin >> posX >> posY;
        cin >> desX >> desY;
        Q.push({ posX, posY });
        dis[posX][posY] = 0;
        while (!(posX == desX && posY == desY)) {
            tie(posX, posY) = Q.front(); Q.pop();
            for (int i = 0; i < 8; i++) {
                int x = posX + dx[i];
                int y = posY + dy[i];
                if (x < 0 || x >= L || y < 0 || y >= L) continue;
                if (dis[x][y] >= 0) continue;
                Q.push({ x, y });
                dis[x][y] = dis[posX][posY] + 1;
            }
        }
        cout << dis[desX][desY] << '\n';
    }

    return 0;
}