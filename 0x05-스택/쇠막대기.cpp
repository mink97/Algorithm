#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int cnt = 0;
    cin >> s;
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push('(');
        }
        else {
            st.pop();
            if (s[i - 1] == '(') {
                cnt += st.size();
            }
            else {
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}