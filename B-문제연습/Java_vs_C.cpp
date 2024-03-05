#include <bits/stdc++.h>
using namespace std;
string str;
#define JAVA 1
#define CPP 2

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> str;
    int flag = 0;
    string ans;
    for (int i = 0; i < str.size(); i++) {
        if (islower(str[i])) {
            ans += str[i];
            continue;
        }
        if (i == 0) {
            cout << "Error!\n";
            return 0;
        }
        if (str[i] == '_') {
            if (i == str.size() - 1 || str[i + 1] == '_' || isupper(str[i + 1]) || flag == JAVA) {
                cout << "Error!\n";
                return 0;
            }
            flag = CPP;
            i++;
            ans += (char)(str[i] - ('a' - 'A'));
        }
        else {
            if (flag == CPP) {
                cout << "Error!\n";
                return 0;
            }
            flag = JAVA;
            ans += '_';
            ans += (char)(str[i] + ('a' - 'A'));
        }
    }
    cout << ans;
    return 0;
}