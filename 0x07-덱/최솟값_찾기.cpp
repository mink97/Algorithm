#include <bits/stdc++.h>
using namespace std;

int N, L;
deque<int> dq;
int arr[5000005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int minValue = INT_MAX;
    for (int i = 0; i < N; i++) {
        if (arr[i] <= minValue) minValue = arr[i];
        if (dq.size() == L) {
            int front = dq.front();
            dq.pop_front();
            if (front == minValue) { // 최소값 다시 찾기
                minValue = *min_element(&arr[i - L + 1], &arr[i + 1]);
            }
        }
        dq.push_back(arr[i]);
        cout << minValue << ' ';
    }
    return 0;
}