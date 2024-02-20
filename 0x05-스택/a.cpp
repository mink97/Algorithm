#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll maxArea = 0;
    stack<pii> s;

    cin >> n;
    while (n != 0) {
        maxArea = 0;
        for (int i = 0; i < n; i++) {
            int idx = i;
            int x;
            cin >> x;
            while (!s.empty() && s.top().first > x) {
                idx = s.top().second;
                maxArea = max(maxArea, (long long)s.top().first * (i - s.top().second));
                s.pop();
            }
            if (s.empty() || s.top().first != x)
                s.push({ x, idx });
        }
        while (!s.empty()) {
            maxArea = max(maxArea, (long long)s.top().first * (n - s.top().second));
            s.pop();
        }
        cout << maxArea << '\n';
        cin >> n;
    }

}
