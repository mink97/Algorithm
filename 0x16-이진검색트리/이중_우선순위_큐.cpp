#include <bits/stdc++.h>
using namespace std;
int t, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> k;
        multiset<int> q;
        for (int i = 0; i < k; i++) {
            char ch;
            int n;
            cin >> ch >> n;
            if (ch == 'I') {
                q.insert(n);
            }
            else if (ch == 'D') {
                if (q.empty()) {
                    continue;
                }
                else if (n == 1) {
                    q.erase(prev(q.end()));
                }
                else if (n == -1) {
                    q.erase(q.begin());
                }
            }
        }
        if (q.empty()) {
            cout << "EMPTY" << "\n";
        }
        else {
            cout << *(prev(q.end())) << " " << *q.begin() << "\n";
        }
    }

    return 0;
}