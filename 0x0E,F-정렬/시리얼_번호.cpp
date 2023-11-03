#include <bits/stdc++.h>
using namespace std;

string arr[52];
int N;

bool cmp(string a, string b)
{
    if (a.size() == b.size()) {
        int an = 0, bn = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] >= '0' && a[i] <= '9') an += a[i] - '0';
        }
        for (int i = 0; i < b.size(); i++) {
            if (b[i] >= '0' && b[i] <= '9') bn += b[i] - '0';
        }
        if (an == bn) {
            for (int i = 0; i < a.size(); i++) {
                if (a[i] != b[i]) return a[i] < b[i];
            }
        }
        else {
            return an < bn;
        }
    }
    else {
        return (a.size() < b.size());
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N, cmp);
    for (int i = 0; i < N; i++) cout << arr[i] << "\n";
    return 0;
}