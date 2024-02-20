#include <bits/stdc++.h>
using namespace std;
int A, B;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> A >> B;
    int i = 1;
    int num = 1;
    int ans = 0;
    while (i < A) {
        i += num;
        num++;
    }
    if (i - 1 < B) {
        ans += (i - A) * (num - 1);
        while (i + num - 1 < B) {
            ans += num * num;
            i += num;
            num++;
        }
        ans += (B - i + 1) * num;
    }
    else {
        ans += (B - A + 1) * (num - 1);
    }

    cout << ans;
    return 0;
}