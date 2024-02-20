#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> m;
int K, L;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> K >> L;
    for (int i = 0; i < L; i++) {
        string student;
        cin >> student;
        m[student] = i;
    }
    vector<pair<string, int>> slist(m.begin(), m.end());
    sort(slist.begin(), slist.end(), [](const pair<string, int>& a, const pair<string, int>& b) { return a.second < b.second; });

    int en = min(K, (int)slist.size());
    for (int i = 0; i < en; i++) {
        cout << slist[i].first << '\n';
    }
    return 0;
}