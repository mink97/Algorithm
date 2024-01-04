#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10]; // 인접한 정점들의 벡터
bool vis[10]; // 방문 여부

// 연결 그래프에서의 순회, 비재귀
void dfs() {
    stack<int> s;
    s.push(1);
    vis[1] = true;
    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        cout << cur << ' ';
        for (auto nxt : adj[cur]) {
            if (vis[nxt]) continue;
            s.push(nxt);
            vis[nxt] = true;
        }
    }
}

// 연결 그래프에서의 순회, 재귀
void dfs2(int cur) {
    vis[cur] = true;
    cout << cur << ' ';
    for (auto nxt : adj[cur]) {
        if (vis[nxt]) continue;
        dfs2(nxt);
    }
}

// 연결 그래프에서의 순회, 비재귀2
void dfs3() {
    stack<int> s;
    s.push(1);
    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        if (vis[cur]) continue; // 중요. 없으면 오류 날 수 있음.
        vis[cur] = true;
        cout << cur << ' ';
        for (auto nxt : adj[cur]) {
            if (vis[nxt]) continue;
            s.push(nxt);
        }
    }
}