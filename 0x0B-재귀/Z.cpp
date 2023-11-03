#include <bits/stdc++.h>
using namespace std;

int z_visit(int n, int r, int c)
{
    if (n == 0) {
        return 0;
    }
    int mid_point = pow(2, n - 1);
    if (r >= mid_point && c >= mid_point) {
        return ((mid_point * mid_point) * 3 + z_visit(n - 1, r - mid_point, c - mid_point));
    }
    else if (r >= mid_point) {
        return ((mid_point * mid_point) * 2 + z_visit(n - 1, r - mid_point, c));
    }
    else if (c >= mid_point) {
        return (mid_point * mid_point + z_visit(n - 1, r, c - mid_point));
    }
    else {
        return (z_visit(n - 1, r, c));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, r, c;
    cin >> n >> r >> c;
    cout << z_visit(n, r, c);
    return 0;
}