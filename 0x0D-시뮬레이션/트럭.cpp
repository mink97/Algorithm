#include <bits/stdc++.h>
using namespace std;

int n, w, L; // 트럭의 수, 다리의 길이, 최대하중
int truck[1002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> w >> L;
    for (int i = 0; i < n; i++) {
        cin >> truck[i];
    }
    int tm = 0;
    int idx = 0;
    int weight = 0; // 다리 위 무게
    queue<pair<int, int>> Q; // 무게, tm
    Q.push({ truck[idx++], ++tm });
    pair<int, int> head = Q.front();
    weight += head.first;
    while (idx < n || !Q.empty()) {
        tm++;
        if (w - (tm - head.second) <= 0) {
            weight -= head.first;
            Q.pop();
        }
        if (idx < n && weight + truck[idx] <= L) {
            Q.push({ truck[idx], tm });
            weight += truck[idx];
            idx++;
        }
        if (!Q.empty())
            head = Q.front();
    }
    cout << tm;
    return 0;
}