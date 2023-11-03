#include <bits/stdc++.h>
using namespace std;
int N, cnt;
pair<int, int> arr[100005];

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
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
    sort(arr, arr + N, compare);
    int end = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i].first >= end) {
            cnt++;
            end = arr[i].second;
        }
    }
    cout << cnt;
    return 0;
}