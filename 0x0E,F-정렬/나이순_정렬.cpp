#include <bits/stdc++.h>
using namespace std;
pair<int, string> arr[100005];
int N;

bool cmp(const pair<int, string>& a, const pair<int, string>& b) {
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int age;
        string name;
        cin >> age >> name;
        arr[i] = { age, name };
    }
    stable_sort(arr, arr + N, cmp);
    for (int i = 0; i < N; i++) {
        cout << arr[i].first << ' ' << arr[i].second << '\n';
    }
    return 0;
}