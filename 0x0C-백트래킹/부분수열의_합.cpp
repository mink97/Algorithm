#include <bits/stdc++.h>
using namespace std;

int arr[20];
int N, S, cnt = 0;

void func(int idx, int total) {
    if (idx == N) {
        if (total == S) cnt++;
        return;
    }
    func(idx + 1, total);
    func(idx + 1, total + arr[idx]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    func(0, 0);
    if (S == 0)
        cnt--;
    cout << cnt;
    return 0;
}