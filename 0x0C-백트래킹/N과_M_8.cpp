#include <bits/stdc++.h>
using namespace std;
int arr[10];
int printArr[10];
int N, M;

void func(int idx, int st) {
    if (idx == M) {
        for (int i = 0; i < M; i++) {
            cout << printArr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = st; i < N; i++) {
        printArr[idx] = arr[i];
        func(idx + 1, i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    func(0, 0);

    return 0;
}