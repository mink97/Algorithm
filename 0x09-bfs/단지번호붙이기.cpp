#include <bits/stdc++.h>
using namespace std;
int N;
string table[30];
bool vis[30][30];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> table[i];
    }
    vector<int> V;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (table[i][j] == '0' || vis[i][j] == true) continue;
            int area = 0;
            vis[i][j] = true;
            queue<pair<int, int>> Q;
            Q.push({ i, j });
            while (!Q.empty()) {
                int curX, curY;
                tie(curX, curY) = Q.front(); Q.pop();
                area++;
                for (int k = 0; k < 4; k++) {
                    int x = curX + dx[k];
                    int y = curY + dy[k];
                    if (x < 0 || x >= N || y < 0 || y >= N) continue;
                    if (vis[x][y] == true || table[x][y] == '0') continue;
                    Q.push({ x, y });
                    vis[x][y] = true;
                }
            }
            V.push_back(area);
        }
    }
    cout << V.size() << '\n';
    sort(V.begin(), V.end());
    for (int i = 0; i < V.size(); i++) {
        cout << V[i] << '\n';
    }
    return 0;
}