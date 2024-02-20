#include <bits/stdc++.h>
using namespace std;
int N, M;
int arr[10];
int printArr[10];

void func(int idx, int st) {
    if (idx == M) {
        for (int i = 0; i < M; i++) {
            cout << printArr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    printArr[idx] = 0;
    for (int i = st; i < N; i++) {
        if (arr[i] != printArr[idx]) {
            printArr[idx] = arr[i];
            func(idx + 1, i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N);
    func(0, 0);
    return 0;
}