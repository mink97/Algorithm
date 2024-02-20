#include <bits/stdc++.h>
using namespace std;
int N, K;
int road[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    fill(road, road + 100005, -1);
    road[N] = 0;
    queue<int> Q;
    Q.push(N);
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        if (cur == K) {
            cout << road[cur];
            return 0;
        }
        if (cur - 1 >= 0 && road[cur - 1] < 0) {
            Q.push(cur - 1);
            road[cur - 1] = road[cur] + 1;
        }
        if (cur + 1 <= 100000 && road[cur + 1] < 0) {
            Q.push(cur + 1);
            road[cur + 1] = road[cur] + 1;
        }
        if (cur * 2 <= 100000 && road[cur * 2] < 0) {
            Q.push(cur * 2);
            road[cur * 2] = road[cur] + 1;
        }
    }
    return 0;
}