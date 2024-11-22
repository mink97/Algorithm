#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, m;
ll state[10];

int bit_cnt(ll x) {
    int ret = 0;
    for (int i = 0; i < max(n, m); i++) {
        ret += (x >> i) & 1;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string name, music;
        cin >> name >> music;
        for (int j = 0; j < m; j++) {
            state[i] = (state[i] << 1) | (music[j] == 'Y');
        }
    }
    pair<int, int> ans = { 0, -1 };
    for (int comb = 0; comb < (1 << n); comb++) {
        ll sum_music = 0;
        for (int i = 0; i < n; i++) {
            if ((comb & (1LL << i)) == 0) continue;
            sum_music |= state[i];
        }
        int song_cnt = bit_cnt(sum_music);
        int guitar_cnt = bit_cnt(comb);
        if (ans.first < song_cnt) ans = { song_cnt, guitar_cnt };
        else if (ans.first == song_cnt && ans.second > guitar_cnt)
            ans = { song_cnt, guitar_cnt };
    }
    cout << ans.second << '\n';
}