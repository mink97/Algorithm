#include <bits/stdc++.h>
using namespace std;
int a[4004];
int b[4004];
int c[4004];
int d[4004];
vector<int> vec1;
vector<int> vec2;
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            vec1.push_back(a[i] + b[j]);
            vec2.push_back(c[i] + d[j]);
        }
    }
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());
    long long cnt = 0;
    for (int i = 0; i < vec2.size(); i++) {
        cnt += upper_bound(vec1.begin(), vec1.end(), -vec2[i]) - lower_bound(vec1.begin(), vec1.end(), -vec2[i]);
    }
    cout << cnt;
    return 0;
}