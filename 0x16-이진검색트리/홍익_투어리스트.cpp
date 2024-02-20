#include <bits/stdc++.h>
using namespace std;
int N, Q;
set<int> hongik;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        if (tmp) hongik.insert(i);
    }
    int pos = 0;
    while (Q--) {
        int cmd;
        cin >> cmd;
        switch (cmd) {
        case 1:
            int loc;
            cin >> loc;
            loc--;
            if (hongik.find(loc) == hongik.end()) hongik.insert(loc);
            else hongik.erase(loc);
            break;

        case 2:
            int mv;
            cin >> mv;
            pos = (pos + mv % N) % N;
            break;

        case 3:
            if (hongik.empty()) {
                cout << -1 << '\n';
                break;
            }
            auto it = hongik.lower_bound(pos);
            if (it == hongik.end()) {
                cout << *hongik.begin() + N - pos << '\n';
            }
            else {
                cout << *it - pos << '\n';
            }
            break;
        }
    }
    return 0;
}