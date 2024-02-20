#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] != s[i + 1]) cnt++;
    }
    cout << (cnt + 1) / 2;
    return 0;
}