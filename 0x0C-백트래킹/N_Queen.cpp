#include <bits/stdc++.h>
using namespace std;

bool isUsed1[32];
bool isUsed2[32];
bool isUsed3[32];
int cnt = 0;
int N;

void func(int cur) {
    if (cur == N) {
        cnt++;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (isUsed1[i] || isUsed2[i + cur] || isUsed3[cur - i + N - 1])
            continue;
        isUsed1[i] = true;
        isUsed2[i + cur] = true;
        isUsed3[cur - i + N - 1] = true;
        func(cur + 1);
        isUsed1[i] = false;
        isUsed2[i + cur] = false;
        isUsed3[cur - i + N - 1] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    func(0);
    cout << cnt;
    return 0;
}