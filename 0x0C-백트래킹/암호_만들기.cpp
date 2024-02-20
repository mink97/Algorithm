#include <bits/stdc++.h>
using namespace std;
int L, C;
char arr[16];
int mark[16];
string vowels = "aeiou";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> L >> C;
    for (int i = 0; i < C; i++) {
        cin >> arr[i];
        mark[i] = i < L ? 0 : 1;
    }
    sort(arr, arr + C);
    do {
        string str;
        int cnt = 0;
        for (int i = 0; i < C; i++) {
            if (mark[i] == 0) {
                str += arr[i];
                if (vowels.find(arr[i]) != string::npos) cnt++;
            }
        }
        if (cnt > 0 && L - cnt > 1)
            cout << str << '\n';
    } while (next_permutation(mark, mark + C));
    return 0;
}