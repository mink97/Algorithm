#include <bits/stdc++.h>
using namespace std;
int n, m;
string arr[100005];
unordered_map<string, int> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        s[arr[i]] = i;
    }
    for (int i = 0; i < m; i++) {
        string str;
        cin >> str;
        if (isdigit(str[0])) {
            cout << arr[stoi(str)] << "\n";
        }
        else {
            cout << s[str] << "\n";
        }
    }
    return 0;
}