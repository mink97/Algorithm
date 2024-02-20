#include <bits/stdc++.h>
using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     string s;
//     cin >> s;
//     int ans = 0;
//     stack<pair<char, int>> st;
//     for (int i = 0; i < s.size(); i++) {
//         switch (s[i]) {
//         case '(':
//             st.push({ s[i], 0 });
//             break;
//         case ')':
//             if (st.empty() || st.top().first != '(') {
//                 cout << 0;
//                 return 0;
//             }
//             else {
//                 int value;
//                 value = st.top().second == 0 ? 2 : st.top().second * 2;
//                 st.pop();
//                 if (st.empty()) {
//                     ans += value;
//                 }
//                 else {
//                     st.top().second += value;
//                 }
//             }
//             break;
//         case '[':
//             st.push({ s[i], 0 });
//             break;
//         case ']':
//             if (st.empty() || st.top().first != '[') {
//                 cout << 0;
//                 return 0;
//             }
//             else {
//                 int value;
//                 value = st.top().second == 0 ? 3 : st.top().second * 3;
//                 st.pop();
//                 if (st.empty()) {
//                     ans += value;
//                 }
//                 else {
//                     st.top().second += value;
//                 }
//             }
//             break;
//         default:
//             break;
//         }
//     }
//     cout << (st.empty() ? ans : 0);
//     return 0;
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int sum = 0, num = 1;
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            num *= 2;
            st.push('(');
        }
        else if (s[i] == ')') {
            if (st.empty() || st.top() != '(') {
                cout << 0;
                return 0;
            }
            if (s[i - 1] == '(') {
                sum += num;
            }
            st.pop();
            num /= 2;
        }
        else if (s[i] == '[') {
            num *= 3;
            st.push('[');
        }
        else if (s[i] == ']') {
            if (st.empty() || st.top() != '[') {
                cout << 0;
                return 0;
            }
            if (s[i - 1] == '[') {
                sum += num;
            }
            st.pop();
            num /= 3;
        }
    }
    cout << (st.empty() ? sum : 0);
    return 0;
}