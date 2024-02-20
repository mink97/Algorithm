#include <bits/stdc++.h>
using namespace std;
set<pair<int, int>> s; // level, problem
int levels[100005];
int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    while (N--) {
        int p, l;
        cin >> p >> l;
        s.insert({ l, p });
        levels[p] = l;
    }
    cin >> M;
    while (M--) {
        string cmd;
        cin >> cmd;
        if (cmd == "add") {
            int p, l;
            cin >> p >> l;
            s.insert({ l, p });
            levels[p] = l;
        }
        else if (cmd == "solved") {
            int p;
            cin >> p;
            s.erase({ levels[p], p });
            levels[p] = 0;
        }
        else if (cmd == "recommend") {
            int x;
            cin >> x;
            switch (x) {
            case 1:
                cout << prev(s.end())->second << '\n';
                break;

            default:
                cout << s.begin()->second << '\n';
                break;
            }
        }
    }
    return 0;
}