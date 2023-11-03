#include <bits/stdc++.h>
using namespace std;
int arr[1002][5];
int D[1002][5];
int N;
int check[3][2] = { {2, 3}, {1, 3}, {1, 2} };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> arr[i][j];
        }
        for (int j = 1; j <= 3; j++) {
            D[i][j] = arr[i][j] + min(D[i - 1][check[j - 1][0]], D[i - 1][check[j - 1][1]]);
        }
    }
    cout << min({ D[N][1], D[N][2], D[N][3] });
    return 0;
}