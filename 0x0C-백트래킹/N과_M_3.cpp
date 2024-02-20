#include <bits/stdc++.h>
using namespace std;
int N, M;

void func(int* arr, int idx) {
    if (idx == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= N; i++) {
        arr[idx] = i;
        func(arr, idx + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    int arr[10] = { 0, };
    func(arr, 0);
    return 0;
}