#include <bits/stdc++.h>
using namespace std;
int N, M;

const int ROOT = 1;
const int MX = 10000 * 500 + 5;
int unused = 2;
bool chk[MX];
int nxt[MX][26];

int c2i(char c) {
    return c - 'a';
}

void insert(string& s) {
    int cur = ROOT;
    for (char c : s) {
        if (nxt[cur][c2i(c)] == -1)
            nxt[cur][c2i(c)] = unused++;
        cur = nxt[cur][c2i(c)];
    }
    chk[cur] = true;
}

bool find(string& s) {
    int cur = ROOT;
    for (char c : s) {
        if (nxt[cur][c2i(c)] == -1)
            return false;
        cur = nxt[cur][c2i(c)];
    }
    return chk[cur];
}

void erase(string& s) {
    int cur = ROOT;
    for (char c : s) {
        if (nxt[cur][c2i(c)] == -1)
            return;
        cur = nxt[cur][c2i(c)];
    }
    chk[cur] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    fill(&nxt[0][0], &nxt[MX - 1][26], -1);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        insert(s);
    }
    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;
        if (find(s))
            ans++;
    }
    cout << ans;
    return 0;
}