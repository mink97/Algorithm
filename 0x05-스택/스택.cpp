#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    stack<int> s;
    int N;
    cin >> N;
    while (N--) {
        string cmd;
        cin >> cmd;
        if (cmd == "push") {
            int x;
            cin >> x;
            s.push(x);
        }
        else if (cmd == "pop") {
            if (s.empty()) {
                cout << "-1" << "\n";
                continue;
            }
            cout << s.top() << "\n";
            s.pop();
        }
        else if (cmd == "size") {
            cout << s.size() << "\n";
        }
        else if (cmd == "empty") {
            cout << s.empty() << "\n";
        }
        else if (cmd == "top") {
            if (s.empty()) {
                cout << "-1" << "\n";
                continue;
            }
            cout << s.top() << "\n";
        }
    }

    return 0;
}