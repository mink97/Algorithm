#include <bits/stdc++.h>
using namespace std;

int arr[1000005];
vector<int> uni;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        uni.push_back(arr[i]);
    }
    sort(uni.begin(), uni.end());
    uni.erase(unique(uni.begin(), uni.end()), uni.end());
    for (int i = 0; i < n; i++) {
        cout << lower_bound(uni.begin(), uni.end(), arr[i]) - uni.begin() << ' ';
    }
    return 0;
}