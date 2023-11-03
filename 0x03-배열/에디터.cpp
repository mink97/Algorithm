#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int N;
    list<char> str;
    list<char>::iterator cursor;
    cin >> s >> N;
    for (char c : s) {
        str.push_back(c);
    }
    cursor = str.end();
    for (int i = 0; i < N; i++)
    {
        char cmd;
        cin >> cmd;
        if (cmd == 'L')
            cursor = (cursor == str.begin() ? cursor : --cursor);
        else if (cmd == 'D')
            cursor = (cursor == str.end() ? cursor : ++cursor);
        else if (cmd == 'B')
            cursor = (cursor == str.begin() ? cursor : str.erase(--cursor));
        else if (cmd == 'P')
        {
            char c;
            cin >> c;
            str.insert(cursor, c);
        }
    }
    for (char c : str) {
        cout << c;
    }

    return 0;
}