#include <bits/stdc++.h>
using namespace std;
int N, M;
int arr[10];
int printArr[10];
int isused[10];

void func(int idx) {
    if (idx == M) {
        for (int i = 0; i < M; i++) {
            cout << printArr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    printArr[idx] = 0;
    for (int i = 0; i < N; i++) {
        if (!isused[i] && arr[i] != printArr[idx]) {
            isused[i] = 1;
            printArr[idx] = arr[i];
            func(idx + 1);
            isused[i] = 0;;
        }
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
    func(0);
    return 0;
}