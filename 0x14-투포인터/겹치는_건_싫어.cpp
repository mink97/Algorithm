#include <bits/stdc++.h>
using namespace std;
int N, K;
int arr[200005];
int isVisit[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int en = 0;
    isVisit[arr[0]]++;
    int ans = 1;
    for (int st = 0; st < N; st++) {
        while (en < N && isVisit[arr[en]] <= K) {
            en++;
            isVisit[arr[en]]++;
        }
        ans = max(ans, en - st);
        if (en == N) break;
        isVisit[arr[st]]--;
    }
    cout << ans;
    return 0;
}