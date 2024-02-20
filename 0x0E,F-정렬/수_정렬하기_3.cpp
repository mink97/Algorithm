#include <bits/stdc++.h>
using namespace std;
int arr[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        arr[tmp]++;
    }
    for (int i = 1; i < 10001; i++) {
        while (arr[i]--) {
            cout << i << '\n';
        }
    }
    return 0;
}