#include <bits/stdc++.h>
using namespace std;
unordered_set<string> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while (n--) {
        string name, log;
        cin >> name >> log;
        if (log == "enter") s.insert(name);
        else s.erase(name);
    }
    vector<string> ans(s.begin(), s.end());
    sort(ans.begin(), ans.end(), greater<string>());
    for (string s : ans) {
        cout << s << "\n";
    }
    return 0;
}