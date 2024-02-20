#include <bits/stdc++.h>
using namespace std;
typedef pair<pair<int, int>, pair<int, int>> dateFormat;
#define sm first.first
#define sd first.second
#define em second.first
#define ed second.second

dateFormat days[100005];
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    pair<int, int> startDay = { 3, 1 };
    pair<int, int> lastDay = { 11, 30 };

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> days[i].sm >> days[i].sd >> days[i].em >> days[i].second.second;
    }
    sort(days, days + N); // 피는 날 기준으로 정렬
    int cnt = 0;
    int idx = 0;
    pair<int, int> start = startDay;
    pair<int, int> end = { 1, 1 };
    while (idx < N) {
        if (days[idx].first > start) {
            cout << 0;
            return 0;
        }
        while (idx < N && days[idx].first <= start) { // 이전 꽃의 지는 날보다 일찍 피는 꽃 중 가장 늦게 지는 꽃 고르기
            if (end < days[idx].second) end = days[idx].second;
            idx++;
        }
        cnt++;
        if (end > lastDay) {
            cout << cnt;
            return 0;
        }
        start = end;
    }
    cout << 0;
    return 0;
}