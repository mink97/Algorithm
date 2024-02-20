#include <bits/stdc++.h>
using namespace std;
int T;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        if (N == 0) {
            cout << 0 << '\n';
            continue;
        }
        unordered_map<string, int> m;
        while (N--) {
            string tmp, type;
            cin >> tmp >> type;
            if (m.find(type) != m.end()) {
                m[type]++;
            }
            else {
                m[type] = 1;
            }
        }
        int ans = 1;
        for (auto e : m) {
            ans *= (e.second + 1);
        }
        ans--;
        cout << ans << '\n';
    }

    return 0;
}