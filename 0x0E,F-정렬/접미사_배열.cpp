#include <bits/stdc++.h>
using namespace std;

vector<string> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        v.push_back(s.substr(i));
    }
    sort(v.begin(), v.end());
    for (auto elem : v) {
        cout << elem << '\n';
    }
    return 0;
}