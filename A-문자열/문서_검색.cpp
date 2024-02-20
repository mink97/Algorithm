#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s, sep;
    getline(cin, s);
    getline(cin, sep);
    size_t pos = 0;
    size_t sz = sep.size();
    int cnt = 0;
    while ((pos = s.find(sep, pos)) != string::npos) {
        cnt++;
        pos += sz;
    }
    cout << cnt;
    return 0;
}