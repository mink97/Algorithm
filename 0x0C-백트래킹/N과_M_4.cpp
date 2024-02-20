#include <bits/stdc++.h>
using namespace std;
int N, M;
int arr[10];

void func(int idx) {
    if (idx == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int st = idx == 0 ? 1 : arr[idx - 1];
    for (int i = st; i <= N; i++) {
        arr[idx] = i;
        func(idx + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    func(0);

    return 0;
}