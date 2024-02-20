#include <bits/stdc++.h>
using namespace std;
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    while (N--) {
        string s;
        int i;
        cin >> s;
        i = 0;
        stack<char> st;
        for (; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push('(');
            }
            else {
                if (st.empty()) {
                    break;
                }
                else {
                    st.pop();
                }
            }
        }
        if (i != s.size() || !st.empty())
            cout << "NO\n";
        else
            cout << "YES\n";

    }
    return 0;
}