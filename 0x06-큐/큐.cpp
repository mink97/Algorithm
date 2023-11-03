#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int> q;
    int N;
    cin >> N;
    while (N--) {
        string cmd;
        cin >> cmd;
        if (cmd == "push") {
            int x;
            cin >> x;
            q.push(x);
            continue;
        }
        else if (cmd == "pop") {
            if (q.empty())
                cout << "-1";
            else {
                cout << q.front();
                q.pop();
            }
        }
        else if (cmd == "empty") {
            cout << q.empty();
        }
        else if (cmd == "size") {
            cout << q.size();
        }
        else if (cmd == "front") {
            if (q.empty())
                cout << "-1";
            else {
                cout << q.front();
            }
        }
        else if (cmd == "back") {
            if (q.empty())
                cout << "-1";
            else {
                cout << q.back();
            }
        }
        cout << "\n";
    }
    return 0;
}