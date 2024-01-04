#include <bits/stdc++.h>
using namespace std;

// bfs 예시 코드 1 - 연결 그래프에서의 순회
vector<int> adj[10];
bool vis[10];
void bfs() {
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for (auto nxt : adj[cur]) {
            if (vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = true;
        }
    }
}

// bfs 예시 코드 2 - 연결 그래프에서 1번 정점과의 거리
vector<int> adj[10];
int dist[10];
void bfs2() {
    fill(dist, dist + 10, -1);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto nxt : adj[cur]) {
            if (dist[nxt] != -1) continue;
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }
}

// BFS 예시 코드 3 - 연결 그래프가 아닐 때 순회
vector<int> adj[10];
bool vis[10];
int v = 9; // = 정점의 수
void bfs3() {
    queue<int> q;
    for (int i = 1; i <= v; i++) {
        if (vis[i]) continue;
        q.push(i);
        vis[i] = true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            cout << cur << ' ';
            for (auto nxt : adj[cur]) {
                if (vis[nxt]) continue;
                q.push(nxt);
                vis[nxt] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    return 0;
}