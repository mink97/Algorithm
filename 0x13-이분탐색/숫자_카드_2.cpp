#include <bits/stdc++.h>
using namespace std;

int arr[500005];
int n;

// int lower_idx(int target) {
//     int st = 0, en = n, mid;

//     while (st < en) {
//         mid = (st + en) / 2;
//         if (arr[mid] >= target) {
//             en = mid;
//         }
//         else {
//             st = mid + 1;
//         }
//     }
//     return st;
// }

// int upper_idx(int target) {
//     int st = 0, en = n, mid;

//     while (st < en) {
//         mid = (st + en) / 2;
//         if (arr[mid] > target) {
//             en = mid;
//         }
//         else {
//             st = mid + 1;
//         }
//     }
//     return st;
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    cin >> m;
    while (m--) {
        int k;
        cin >> k;
        cout << upper_bound(arr, arr + n, k) - lower_bound(arr, arr + n, k) << ' ';
    }
    return 0;
}