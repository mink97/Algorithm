#include <bits/stdc++.h>
using namespace std;
int N, M;
const int ROOT = 1;
int unused = 2;
const int MX = 10000 * 500 + 5;
// bool chk[MX];
int nxt[MX][26];

int c2i(char ch) {
    return ch - 'a';
}

void insert(string& s) {
    int cur = ROOT;
    for (auto c : s) {
        if (nxt[cur][c2i(c)] == -1) nxt[cur][c2i(c)] = unused++;
        cur = nxt[cur][c2i(c)];
    }
    // chk[cur] = true;
}

bool find(string& s) {
    int cur = ROOT;
    for (auto c : s) {
        if (nxt[cur][c2i(c)] == -1) return false;
        cur = nxt[cur][c2i(c)];
    }
    // return chk[cur];
    return true;
}

void erase(string& s) {
    int cur = ROOT;
    for (auto c : s) {
        if (nxt[cur][c2i(c)] == -1) return;
        cur = nxt[cur][c2i(c)];
    }
    // chk[cur] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    fill(&nxt[0][0], &nxt[MX - 1][26], -1);

    int cnt = 0;
    while (N--) {
        string tmp;
        cin >> tmp;
        insert(tmp);
    }
    while (M--) {
        string tmp;
        cin >> tmp;
        cnt += find(tmp);
    }
    cout << cnt;
    return 0;
}