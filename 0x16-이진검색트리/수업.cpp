#include <bits/stdc++.h>
using namespace std;
int N;
pair<int, int> students[500005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> students[i].first >> students[i].second;
    }
    sort(students, students + N, greater<pair<int, int>>());
    vector<int> groups;
    for (int i = 0; i < N; i++) {
        auto g = upper_bound(groups.begin(), groups.end(), -students[i].second);
        if (g == groups.end()) groups.push_back(-1);
        else (*g)--;
    }
    cout << groups.size();
    return 0;
}