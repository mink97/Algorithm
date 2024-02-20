#include <bits/stdc++.h>
using namespace std;
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    while (N--) {
        string cmd, nums;
        int len;
        deque<int> dq;
        bool isBack = false;
        bool isError = false;
        cin >> cmd >> len >> nums;
        int num = 0;
        for (int i = 1; i < nums.size(); i++) {
            if ((nums[i] == ',' || nums[i] == ']') && num != 0) {
                dq.push_back(num);
                num = 0;
            }
            else if (isdigit(nums[i])) {
                num = num * 10 + nums[i] - '0';
            }
        }
        for (int i = 0; i < cmd.size(); i++) {
            if (cmd[i] == 'R') isBack = !isBack;
            else {
                if (dq.empty()) {
                    cout << "error\n";
                    isError = true;
                    break;
                }
                if (isBack) {
                    dq.pop_back();
                }
                else {
                    dq.pop_front();
                }
            }
        }
        if (isError)
            continue;
        cout << '[';
        for (int i = 0; i < dq.size(); i++) {
            cout << (isBack ? dq[dq.size() - 1 - i] : dq[i]);
            if (i != dq.size() - 1) cout << ',';
        }
        cout << ']' << '\n';
    }

    return 0;
}