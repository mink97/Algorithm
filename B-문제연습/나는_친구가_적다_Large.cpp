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
    string S, K;
    cin >> S >> K;
    vector<int> f = failure(K);
    int j = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] >= '0' && S[i] <= '9') continue;
        while (j > 0 && S[i] != K[j]) j = f[j - 1];
        if (S[i] == K[j]) {
            j++;
            if (j == K.size()) {
                cout << 1;
                return 0;
            }
        }
    }
    cout << 0;
    return 0;
}