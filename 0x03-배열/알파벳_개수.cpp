#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[26] = {0, };
    string s;
    cin >> s;
    for (int alp : s) {
        arr[alp - 'a']++;
    }
    for (int arg : arr) {
        cout << arg << " ";
    }
}