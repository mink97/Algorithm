#include <bits/stdc++.h>
using namespace std;
int N, K;
vector<int> vec;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        if (num % 2 == 0) vec.push_back(i);
    }
    if (vec.empty()) {
        cout << 0;
        return 0;
    }
    int st = 0;
    int en = 1;
    int len = vec.size();
    int ans = 1;
    int deleteCnt = 0;
    for (; st < len - 1; st++) {
        while (en < len && deleteCnt <= K) {
            deleteCnt += vec[en] - vec[en - 1] - 1;
            if (deleteCnt <= K) {
                ans = max(ans, en - st + 1);
            }
            en++;
        }
        if (en == len) break;
        deleteCnt -= vec[st + 1] - vec[st] - 1;
    }
    cout << ans;
    return 0;
}