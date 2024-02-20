#include <bits/stdc++.h>
using namespace std;
int N;

int isGoodWord(string& s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (st.empty() || st.top() != s[i]) {
            st.push(s[i]);
        }
        else {
            st.pop();
        }
    }
    if (!st.empty()) return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int ans = 0;
    cin >> N;
    while (N--) {
        string s;
        cin >> s;
        ans += isGoodWord(s);
    }
    cout << ans;
    return 0;
}