#include <bits/stdc++.h>
using namespace std;

stack<pair<int, int>> st;
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    long long cnt = 0;
    while (N--) {
        int height;
        cin >> height;
        while (!st.empty() && st.top().first < height) {
            cnt += st.top().second;
            st.pop();
        }
        if (st.empty()) {
            st.push({ height, 1 });
        }
        else if (st.top().first == height) {
            cnt += (st.size() == 1 ? st.top().second : st.top().second + 1);
            st.top().second++;
        }
        else {
            st.push({ height, 1 });
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}