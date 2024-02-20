#include <bits/stdc++.h>
using namespace std;
int N;
stack<int> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    long long ans = 0;
    while (N--) {
        int height;
        cin >> height;
        while (!st.empty() && st.top() <= height) {
            st.pop();
        }
        ans += st.size();
        st.push(height);
    }
    cout << ans;
    return 0;
}