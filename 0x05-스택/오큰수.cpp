#include <bits/stdc++.h>
using namespace std;

// {높이, 인덱스}
stack<pair<int, int>> st;
int ans[1000005];
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    fill(ans, ans + N, -1);
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        while (!st.empty() && st.top().first < num) {
            ans[st.top().second] = num;
            st.pop();
        }
        st.push({ num, i });
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}