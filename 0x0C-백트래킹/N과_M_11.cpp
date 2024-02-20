#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> arr;
int printArr[10];
bool isused[10005];

void func(int idx) {
    if (idx == M) {
        for (int i = 0; i < M; i++) {
            cout << printArr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < arr.size(); i++) {
        printArr[idx] = arr[i];
        func(idx + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (!isused[num]) {
            arr.push_back(num);
            isused[num] = true;
        }
    }
    sort(arr.begin(), arr.end());
    func(0);
    return 0;
}