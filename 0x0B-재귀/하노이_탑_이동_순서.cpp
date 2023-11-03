#include <bits/stdc++.h>
using namespace std;

void move(int start, int dest, int num) {
    int mid = 6 - start - dest;
    if (num == 1) {
        cout << start << " " << dest << "\n";
        return;
    }
    move(start, mid, num - 1);
    cout << start << " " << dest << "\n";
    move(mid, dest, num - 1);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout << (1 << n) - 1 << "\n";
    move(1, 3, n);
    return 0;
}