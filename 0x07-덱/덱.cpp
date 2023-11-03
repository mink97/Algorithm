#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    deque<int> DQ;
    while (N--) {
        string str;
        cin >> str;
        if (str == "push_front") {
            int x;
            cin >> x;
            DQ.push_front(x);
        }
        else if (str == "push_back") {
            int x;
            cin >> x;
            DQ.push_back(x);
        }
        else if (str == "pop_front") {
            if (DQ.empty())
                cout << "-1\n";
            else {
                cout << DQ.front() << "\n";
                DQ.pop_front();
            }
        }
        else if (str == "pop_back") {
            if (DQ.empty())
                cout << "-1\n";
            else {
                cout << DQ.back() << "\n";
                DQ.pop_back();
            }
        }
        else if (str == "front") {
            if (DQ.empty())
                cout << "-1\n";
            else
                cout << DQ.front() << "\n";
        }
        else if (str == "back") {
            if (DQ.empty())
                cout << "-1\n";
            else {
                cout << DQ.back() << "\n";
            }
        }
        else if (str == "size") {
            cout << DQ.size() << "\n";
        }
        else if (str == "empty") {
            cout << DQ.empty() << "\n";
        }
    }
    return 0;
}