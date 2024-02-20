#include <bits/stdc++.h>
using namespace std;
string arr[20005];
int N;

bool cmp(string a, string b) {
    size_t sa, sb;
    sa = a.size();
    sb = b.size();
    if (sa == sb) {
        return a < b;
    }
    return sa < sb;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N, cmp);
    for (int i = 0; i < N; i++) {
        if (i != 0 && arr[i - 1] == arr[i]) continue;
        cout << arr[i] << '\n';
    }

    return 0;
}