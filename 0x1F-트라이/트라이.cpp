#include <bits/stdc++.h>
using namespace std;

//변수
const int ROOT = 1;
int unused = 2;
const int MX = 10000 * 500 + 5;
bool chk[MX];
int nxt[MX][26];


int c2i(char c) {
    return c - 'A';
}

// insert
void insert(string& s) {
    int cur = ROOT;
    for (auto c : s) {
        if (nxt[cur][c2i(c)] == -1)
            nxt[cur][c2i(c)] = unused++;
        cur = nxt[cur][c2i(c)];
    }
    chk[cur] = true;
}

// find
bool find(string& s) {
    int cur = ROOT;
    for (auto c : s) {
        if (nxt[cur][c2i(c)] == -1)
            return false;
        cur = nxt[cur][c2i(c)];
    }
    return chk[cur];
}

// erase
void erase(string& s) {
    int cur = ROOT;
    for (auto c : s) {
        if (nxt[cur][c2i(c)] == -1)
            return;
        cur = nxt[cur][c2i(c)];
    }
    chk[cur] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    fill(&nxt[0][0], &nxt[MX - 1][26], -1);


    return 0;
}