#include <bits/stdc++.h>
using namespace std;
int arr[2000005];
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        arr[tmp + 1000000]++;
    }
    for (int i = 0; i < 2000001; i++) {
        while (arr[i]-- > 0) {
            cout << i - 1000000 << "\n";
        }
    }
    return 0;
}