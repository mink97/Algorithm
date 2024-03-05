#include <bits/stdc++.h>
using namespace std;
// 위상정렬
vector<int> adj[1005];
int indegree[1005];
vector<int> ord;
int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    while (M--) {
        int t;
        cin >> t;
        int prevSinger = 0;
        for (int i = 0; i < t; i++) {
            int curSinger;
            cin >> curSinger;
            if (prevSinger != 0) {
                adj[prevSinger].push_back(curSinger);
                indegree[curSinger]++; // 위상정렬을 위한 indegree 수
            }
            prevSinger = curSinger;
        }
    }
    // 위상정렬 시작
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        ord.push_back(cur);
        for (auto nxt : adj[cur]) {
            indegree[nxt]--;
            if (indegree[nxt] == 0) {
                q.push(nxt);
            }
        }
    }
    if (ord.size() == N) {
        for (auto e : ord) {
            cout << e << '\n';
        }
    }
    else {
        cout << 0;
    }
    return 0;
}