#include <bits/stdc++.h>
// parametric search
using namespace std;

bool solve(const vector<int>& times, int n, long long val) {
    int cnt = 0;
    for (int i = 0; i < times.size(); i++) {
        cnt += times[i] / val;
    }
    return cnt >= n;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long st = 0;
    long long en = LONG_MAX;
    long long en = LONG_MAX;
    long long en = LONG_MAX;
    while (st < en) {
        long long mid = (st + en + 1) / 2;
        if (solve(times, n, mid)) {
            st = mid;
        } else {
            en = mid - 1;
        }
    }
    return st;
}