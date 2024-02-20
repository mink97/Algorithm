#include <bits/stdc++.h>
using namespace std;
short arr[10];
short N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    vector<uint8_t> V;
    for (uint8_t i = 0; i < N; i++) {
        cin >> arr[i];
        V.push_back(i < M ? 0 : 1);
    }
    sort(arr, arr + N);
    do {
        for (uint8_t i = 0; i < N; i++) {
            if (V[i] == 0)
                cout << arr[i] << ' ';
        }
        cout << '\n';
    } while (next_permutation(V.begin(), V.end()));

    return 0;
}