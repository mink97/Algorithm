#include <bits/stdc++.h>
using namespace std;
short arr[10];
short printArr[10];
int N, M;

void func(int idx) {
    if (idx == M) {
        for (char i = 0; i < M; i++) {
            cout << printArr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (char i = 0; i < N; i++) {
        printArr[idx] = arr[i];
        func(idx + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (char i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    func(0);
    return 0;
}