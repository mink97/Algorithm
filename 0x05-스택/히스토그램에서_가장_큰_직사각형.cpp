#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    stack<pair<int, int>> st; // {height, index}
    int N;
    cin >> N;
    while (N != 0) {
        long long mx_area = 0;
        for (int i = 0; i < N; i++) {
            int idx = i;
            int cur_height;
            cin >> cur_height;
            while (!st.empty() && st.top().first > cur_height) {
                int height;
                tie(height, idx) = st.top(); st.pop();
                if ((long long)height * (i - idx) > mx_area) {
                    mx_area = (long long)height * (i - idx);
                }
            }
            if (st.empty() || st.top().first < cur_height)
                st.push({ cur_height, idx }); // idx는 가능한 시작부분에 가까운 인덱스를 넣어야되는데 깜빡하고 생각없이 그냥 현재 인덱스를 넣어버렸네
        }
        while (!st.empty()) {
            int height, idx;
            tie(height, idx) = st.top(); st.pop();
            if ((long long)height * (N - idx) > mx_area) {
                mx_area = (long long)height * (N - idx);
            }
        }
        cout << mx_area << "\n";
        cin >> N;
    }


    return 0;
}