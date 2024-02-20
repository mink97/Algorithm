#include <bits/stdc++.h>
using namespace std;
int N;
int arr[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int a, b;
    int minValue = INT_MAX;
    for (int i = 0; i < N - 1; i++) {
        int valueA = arr[i];
        int valueB;
        int idxB = lower_bound(arr + i + 1, arr + N, -valueA) - arr;
        if (idxB == N) idxB = N - 1;
        else {
            if (idxB > i + 1 && abs(valueA + arr[idxB - 1]) < abs(valueA + arr[idxB])) idxB--;
        }
        valueB = arr[idxB];
        if (abs(valueA + valueB) < minValue) {
            a = valueA;
            b = valueB;
            minValue = abs(valueA + valueB);
        }
    }
    cout << a << ' ' << b;
    return 0;
}