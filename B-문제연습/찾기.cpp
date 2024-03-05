#include <bits/stdc++.h>
using namespace std;
// KMP

vector<int> failure(string& s) {
    vector<int> f(s.size());
    int j = 0;
    for (int i = 1; i < s.size(); i++) {
        while (j > 0 && s[i] != s[j]) j = f[j - 1];
        if (s[i] == s[j]) f[i] = ++j;
    }
    return f;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string T, P;
    getline(cin, T);
    getline(cin, P);
    vector<int> f = failure(P);
    int cnt = 0;
    vector<int> v;
    int j = 0;
    for (int i = 0; i < T.size(); i++) {
        while (j > 0 && T[i] != P[j]) j = f[j - 1];
        if (T[i] == P[j]) {
            j++;
            if (j == P.size()) {
                cnt++;
                v.push_back(i - j + 2);
                j = f[j - 1];
            }
        }
    }
    cout << cnt << '\n';
    for (auto i : v) {
        cout << i << ' ';
    }
    return 0;
}