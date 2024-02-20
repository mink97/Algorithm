#include <bits/stdc++.h>
using namespace std;
int arr[1002];
int lenArr[1002];
int pre[1002];
int n, preI;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int mxLen = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        lenArr[i] = 1;
        for (int j = 1; j < i; j++) {
            if (arr[j] < arr[i]) {
                if (lenArr[j] + 1 > lenArr[i]) {
                    lenArr[i] = lenArr[j] + 1;
                    pre[i] = j;
                }
            }
        }
        if (mxLen < lenArr[i]) {
            mxLen = lenArr[i];
            preI = i;
        }
    }
    cout << mxLen << '\n';
    stack<int> st;
    while (preI != 0) {
        st.push(preI);
        preI = pre[preI];
    }
    while (!st.empty()) {
        int i = st.top(); st.pop();
        cout << arr[i] << ' ';
    }
    return 0;
}