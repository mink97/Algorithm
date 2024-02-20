#include <bits/stdc++.h>
using namespace std;
pair<int, int> arr[100005];
int N;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        arr[i] = { a, b };
    }
    sort(arr, arr + N, cmp);
    for (int i = 0; i < N; i++) {
        cout << arr[i].first << ' ' << arr[i].second << '\n';
    }
    return 0;
}