#include <bits/stdc++.h>
using namespace std;
int crossPoint[5] = { 0, 2, 2, 2, 2 };
string gear[5];
int K;

void rotate(int num, int rot) {
    if (rot == 1) { // 시계방향
        crossPoint[num] = crossPoint[num] == 0 ? 7 : crossPoint[num] - 1;
    }
    else if (rot == -1) { // 반시계방향
        crossPoint[num] = crossPoint[num] == 7 ? 0 : crossPoint[num] + 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 1; i <= 4; i++) {
        cin >> gear[i];
    }
    cin >> K;
    while (K--) {
        int num, rot;
        int rotatable[5] = { 0, };
        cin >> num >> rot;
        rotatable[num] = rot;
        // 왼쪽
        int curGear = num;
        while (curGear > 1) {
            int left_idx = crossPoint[curGear - 1];
            int right_idx = (crossPoint[curGear] + 4) % 8;
            if (gear[curGear - 1][left_idx] == gear[curGear][right_idx]) {
                break;
            }
            else {
                rotatable[curGear - 1] = rotatable[curGear] * -1;
                curGear--;
            }
        }
        // 오른쪽
        curGear = num;
        while (curGear < 4) {
            int left_idx = crossPoint[curGear];
            int right_idx = (crossPoint[curGear + 1] + 4) % 8;
            if (gear[curGear][left_idx] == gear[curGear + 1][right_idx]) {
                break;
            }
            else {
                rotatable[curGear + 1] = rotatable[curGear] * -1;
                curGear++;
            }
        }
        for (int i = 1; i <= 4; i++) {
            if (rotatable[i] != 0) {
                rotate(i, rotatable[i]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= 4; i++) {
        int idx = (crossPoint[i] + 6) % 8;
        if (gear[i][idx] == '1') {
            ans += (1 << (i - 1));
        }
    }
    cout << ans;
    return 0;
}