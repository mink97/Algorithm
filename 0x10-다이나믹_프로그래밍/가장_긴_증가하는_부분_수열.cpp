#include <bits/stdc++.h>
using namespace std;
int arr[1002];
int lenArr[1002];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int mxLen = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        lenArr[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) lenArr[i] = max(lenArr[j] + 1, lenArr[i]);
        }
        mxLen = max(mxLen, lenArr[i]);
    }
    cout << mxLen;
    return 0;
}