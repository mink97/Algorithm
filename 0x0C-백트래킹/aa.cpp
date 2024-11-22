#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> ans;
    for (int idx = 0; idx < commands.size(); idx++) {
        int i, j, k;
        tie(i, j, k) = { commands[idx][0], commands[idx][1], commands[idx][2] };
        vector<int> tmp(array.begin() + i - 1, array.begin() + j);
        sort(tmp.begin(), tmp.begin() + j - i + 1);
        ans.push_back(tmp[k - 1]);
    }
    return ans;
}