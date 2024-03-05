#include <bits/stdc++.h>
using namespace std;
int N;

vector<int> failure(string& s) {
    vector<int> ret(s.size());
    int j = 0;
    for (int i = 1; i < s.size(); i++) {
        while (j != 0 && s[i] != s[j]) j = ret[j - 1];
        if (s[i] == s[j]) ret[i] = ++j;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    string s;
    cin >> s;
    int pos = s.find('*');
    string str1 = s.substr(0, pos);
    string str2 = s.substr(pos + 1);
    vector<int> f1 = failure(str1);
    vector<int> f2 = failure(str2);
    while (N--) {
        string target;
        cin >> target;
        int j = 0;
        bool flag = false;
        for (int i = 0; i < target.size(); i++) {
            if (target[i] == str1[j]) j++;
            else break;
            if (j == str1.size()) { // 앞 통과, 뒤 확인
                int b = 0;
                for (int a = i + 1; a < target.size(); a++) {
                    while (b > 0 && target[a] != str2[b]) b = f2[b - 1];
                    if (target[a] == str2[b]) {
                        b++;
                        if (b == str2.size() && a == target.size() - 1) {
                            flag = true;
                            cout << "DA\n";
                            break;
                        }
                    }
                }
                break;
            }
        }
        if (!flag) cout << "NE\n";
    }
    return 0;
}