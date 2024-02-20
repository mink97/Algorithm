#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int ans = -1002;
    int curMX = -1002;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        curMX = curMX < 0 ? num : curMX + num;
        ans = max(curMX, ans);
    }
    cout << ans;
    return 0;
}