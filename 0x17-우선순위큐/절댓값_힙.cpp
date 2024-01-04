#include <bits/stdc++.h>
using namespace std;
int N;

struct compare
{
    bool operator()(int& a, int& b) {
        if (abs(a) != abs(b)) {
            return abs(a) > abs(b);
        }
        return a > b;
    }
};

priority_queue<int, vector<int>, compare> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    while (N--) {
        int n;
        cin >> n;
        if (n == 0) {
            if (pq.empty()) {
                cout << "0\n";
            }
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else {
            pq.push(n);
        }
    }

    return 0;
}