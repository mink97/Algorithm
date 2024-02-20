#include <bits/stdc++.h>
using namespace std;
int arr[1002];
int sumArr[1002];
int n;
int mxSum;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin >> arr[0];
    sumArr[0] = arr[0];
    mxSum = sumArr[0];
    for (int i = 1; i < n; i++) {
        cin >> arr[i];
        sumArr[i] = arr[i];
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] < arr[i]) {
                sumArr[i] = max(sumArr[j] + arr[i], sumArr[i]);
            }
        }
        mxSum = max(mxSum, sumArr[i]);
    }
    cout << mxSum;
    return 0;
}