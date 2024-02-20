#include <bits/stdc++.h>
using namespace std;
int arr[14];
int comb[14] = { 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1 };
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    while (N != 0) {
        for (int i = 0; i < N; i++) cin >> arr[i];
        do {
            for (int i = 0; i < N; i++) {
                if (comb[i] == 0) cout << arr[i] << ' ';
            }
            cout << '\n';
        } while (next_permutation(comb, comb + N));
        cout << '\n';
        cin >> N;
    }
    return 0;
}