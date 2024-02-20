#include <bits/stdc++.h>
using namespace std;

vector<string> alphas = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    for (string alpha : alphas) {
        while (true) {
            size_t pos = s.find(alpha, 0);
            if (pos == string::npos) break;
            s.replace(pos, alpha.size(), "#");
        }
    }
    cout << s.size();
    return 0;
}