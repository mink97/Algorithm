#include <bits/stdc++.h>
using namespace std;
const int ROOT = 1;
int unused = 2;
const int MX = 10000 * 10 + 5;
bool chk[MX];
int nxt[MX][10];

int T, N;

int c2i(char c) {
    return c - '0';
}

bool insert(string& s) {
    int cur = ROOT;
    int flag = true;
    for (auto c : s) {
        if (chk[cur]) break;
        if (nxt[cur][c2i(c)] == -1) {
            flag = false;
            nxt[cur][c2i(c)] = unused++;
        }
        cur = nxt[cur][c2i(c)];
    }
    chk[cur] = true;
    return flag;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> N;
        fill(&nxt[0][0], &nxt[MX - 1][10], -1);
        fill(chk, chk + MX, false);
        unused = 2;
        bool flag = true;
        while (N--) {
            string tmp;
            cin >> tmp;
            if (flag) {
                if (insert(tmp) == true) {
                    flag = false;
                }
            }
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}