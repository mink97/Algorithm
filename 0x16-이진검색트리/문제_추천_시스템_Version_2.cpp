#include <bits/stdc++.h>
using namespace std;
set<int> LGP[102][102]; // [level][group]
set<int> LP[102];

pair<int, int> problemInfo[100005]; // 
int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    while (N--) {
        int P, L, G;
        cin >> P >> L >> G;
        LGP[L][G].insert(P);
        LP[L].insert(P);
        problemInfo[P] = { L, G };
    }
    cin >> M;
    while (M--) {
        string cmd;
        cin >> cmd;
        if (cmd == "recommend") {
            int G, x;
            cin >> G >> x;
            if (x == 1) {
                for (int i = 100; i >= 1; i--) {
                    if (LGP[i][G].empty()) continue;
                    cout << *prev(LGP[i][G].end()) << '\n';
                    break;
                }
            }
            else {
                for (int i = 1; i <= 100; i++) {
                    if (LGP[i][G].empty()) continue;
                    cout << *LGP[i][G].begin() << '\n';
                    break;
                }
            }
        }
        else if (cmd == "recommend2") {
            int x;
            cin >> x;
            if (x == 1) {
                int recmd = 0;
                for (int i = 100; i >= 1; i--) {
                    if (LP[i].empty()) continue;
                    cout << *prev(LP[i].end()) << '\n';
                    break;
                }
            }
            else {
                int recmd = 100005;
                for (int i = 1; i <= 100; i++) {
                    if (LP[i].empty()) continue;
                    cout << *LP[i].begin() << '\n';
                    break;
                }
            }
        }
        else if (cmd == "recommend3") {
            int x, L;
            cin >> x >> L;
            if (x == 1) {
                int i = L;
                for (; i <= 100; i++) {
                    if (LP[i].empty()) continue;
                    cout << *LP[i].begin() << '\n';
                    break;
                }
                if (i == 101) cout << -1 << '\n';
            }
            else {
                int i = L - 1;
                for (; i >= 1; i--) {
                    if (LP[i].empty()) continue;
                    cout << *prev(LP[i].end()) << '\n';
                    break;
                }
                if (i == 0) cout << -1 << '\n';
            }
        }
        else if (cmd == "add") {
            int P, L, G;
            cin >> P >> L >> G;
            LGP[L][G].insert(P);
            LP[L].insert(P);
            problemInfo[P] = { L, G };
        }
        else if (cmd == "solved") {
            int P, L, G;
            cin >> P;
            L = problemInfo[P].first;
            G = problemInfo[P].second;
            LGP[L][G].erase(P);
            LP[L].erase(P);
            problemInfo[P] = { 0, 0 };
        }
    }
    return 0;
}