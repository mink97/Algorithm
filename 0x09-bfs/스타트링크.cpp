#include <bits/stdc++.h>
using namespace std;
int F, S, G, U, D;
// Floor, Start, Goal, Up, Down

int height[1000005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> F >> S >> G >> U >> D;
    fill(height, height + F + 1, -1);
    queue<int> Q;
    Q.push(S);
    height[S] = 0;
    while (!Q.empty()) {
        int curPos = Q.front(); Q.pop();
        if (curPos == G) {
            cout << height[curPos];
            return 0;
        }
        int up = curPos + U;
        if (up <= F && height[up] == -1) {
            Q.push(up);
            height[up] = height[curPos] + 1;
        }
        int dn = curPos - D;
        if (dn > 0 && height[dn] == -1) {
            Q.push(dn);
            height[dn] = height[curPos] + 1;
        }
    }
    cout << "use the stairs";
    return 0;
}