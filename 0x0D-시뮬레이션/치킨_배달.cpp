#include <bits/stdc++.h>
using namespace std;
int N, M;
int board[52][52];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int distance(pair<int, int> hs, pair<int, int> ck) {
    return (abs(hs.first - ck.first) + abs(hs.second - ck.second));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    // 입력값 받기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                house.push_back({ i, j });
            }
            else if (board[i][j] == 2) {
                chicken.push_back({ i, j });
            }
        }
    }
    int ans = 0x7f7f7f7f;
    vector<int> choice(chicken.size(), 1);
    fill(choice.begin(), choice.begin() + chicken.size() - M, 0);
    do {
        int dist = 0;
        for (pair<int, int> h : house) {
            int tmp = 102;
            for (int i = 0; i < choice.size(); i++) {
                if (choice[i] == 0) continue;
                tmp = min(tmp, distance(h, chicken[i]));
            }
            dist += tmp;
        }
        ans = min(ans, dist);
    } while (next_permutation(choice.begin(), choice.end()));
    cout << ans;
    return 0;
}