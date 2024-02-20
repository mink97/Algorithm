#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int, string>> v;
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        string n;
        int k, e, m;
        cin >> n >> k >> e >> m;
        v.push_back({ -k, e, -m, n });
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++) {
        cout << get<3>(v[i]) << '\n';
    }
    return 0;
}