#include <bits/stdc++.h>
using namespace std;
int N;
int arr[100005];
bool isVisit[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    long long cnt = 0;
    for (int i = 0; i < N; i++) cin >> arr[i];
    int st = 0;
    int en = 1;
    isVisit[arr[0]] = true;
    while (en < N) {
        if (isVisit[arr[en]]) {
            while (isVisit[arr[en]]) {
                cnt += en - st;
                isVisit[arr[st++]] = false;
            }
        }
        isVisit[arr[en++]] = true;
    }
    cnt += (long long)(en - st) * (en - st + 1) / 2;
    cout << cnt;
    return 0;
}