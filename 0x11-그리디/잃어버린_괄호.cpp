#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string input;
    cin >> input;
    size_t pos = 0;
    int ans = 0;
    bool flag = true;
    while (input.size() > 0) {
        int num = stoi(input, &pos);
        ans = flag ? ans + num : ans - num;
        if (input[pos] == '-') {
            flag = false;
            pos++;
        }
        input = input.substr(pos);
    }
    cout << ans;
    return 0;
}