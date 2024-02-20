#include <bits/stdc++.h>
using namespace std;
int N;
int s[1000005];
int e[1000005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s[i] >> e[i];
    }
    sort(s, s + N);
    sort(e, e + N);
    int len = 0;
    int j = 0;
    int start = 0;
    for (int i = 0; i < N; i++) {
        while (j < N && s[j] < e[i]) j++;
        if (j - 1 == i) {
            len += e[i] - s[start];
            start = j;
        }
    }
    cout << len;
    return 0;
}