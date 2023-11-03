#include <bits/stdc++.h>
using namespace std;
int alist[52], blist[52];
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> alist[i];
    for (int i = 0; i < N; i++)
        cin >> blist[i];
    sort(alist, alist + N);
    sort(blist, blist + N);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans += (alist[i] * blist[N - 1 - i]);
    }
    cout << ans;
    return 0;
}