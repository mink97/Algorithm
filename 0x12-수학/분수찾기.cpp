#include <bits/stdc++.h>
using namespace std;
int X;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> X;
    pair<int, int> pos = { 1, 1 };
    int num = 1;
    while (true) {
        if (num == X) {
            cout << pos.first << '/' << pos.second;
            return 0;
        }
        pos.second++;
        num++;
        if (num == X) {
            cout << pos.first << '/' << pos.second;
            return 0;
        }
        while (pos.second != 1) {
            pos.first++;
            pos.second--;
            num++;
            if (num == X) {
                cout << pos.first << '/' << pos.second;
                return 0;
            }
        }
        pos.first++;
        num++;
        if (num == X) {
            cout << pos.first << '/' << pos.second;
            return 0;
        }
        while (pos.first != 1) {
            pos.first--;
            pos.second++;
            num++;
            if (num == X) {
                cout << pos.first << '/' << pos.second;
                return 0;
            }
        }
    }
    return 0;
}