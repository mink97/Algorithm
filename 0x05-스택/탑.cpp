#include <bits/stdc++.h>
using namespace std;

stack<pair<int, int>> st;
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    st.push({ 100000005, 0 }); // {높이, 번호}
    for (int i = 1; i <= N; i++) {
        int height;
        cin >> height;
        while (st.top().first < height) {
            st.pop();
        }
        cout << st.top().second << ' ';
        st.push({ height, i });
    }

    return 0;
}