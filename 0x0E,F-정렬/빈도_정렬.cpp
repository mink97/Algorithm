#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;
int N, C;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        vector<pair<int, int>>::iterator it = find_if(v.begin(), v.end(), [&tmp](pair<int, int> elem) {return elem.first == tmp; });
        if (it != v.end()) {
            it->second++;
        }
        else {
            v.push_back({ tmp, 1 });
        }
    }
    stable_sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].second; j++) {
            cout << v[i].first << ' ';
        }
    }
    return 0;
}
