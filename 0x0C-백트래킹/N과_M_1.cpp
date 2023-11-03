#include <bits/stdc++.h>
using namespace std;

int isused[10];
int N, M;

void tmp(int* arr, int idx) {
    if (idx == M) {
        for (int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
    for (int n = 1; n <= N; n++) {
        if (!isused[n]) {
            arr[idx] = n;
            isused[n] = 1;
            tmp(arr, idx + 1);
            isused[n] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    int arr[8] = { 0, };
    tmp(arr, 0);
    return 0;
}