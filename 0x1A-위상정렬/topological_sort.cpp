#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10];
int deg[10];
int n;

void topological_sort() {
    queue<int> q;
    vector<int> result;

    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        result.push_back(cur);
        for (auto nxt : adj[cur]) {
            deg[nxt]--;
            if (deg[nxt] == 0) q.push(nxt);
        }
    }
    if (result.size() != n) cout << "cycle exists\n";
    else {
        for (int i = 0; i < n; i++)
            cout << result[i] << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    return 0;
}