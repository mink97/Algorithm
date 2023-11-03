#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    while (getline(cin, str)) {
        if (str == ".")
            return (0);
        int i = 0;
        stack<char> S;
        while ((i = str.find_first_of("({[]})", i)) != str.npos) {
            if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
                S.push(str[i]);
            }
            else if (str[i] == ')') {
                if (S.empty() || S.top() != '(') {
                    break;
                }
                S.pop();
            }
            else if (str[i] == '}') {
                if (S.empty() || S.top() != '{') {
                    break;
                }
                S.pop();
            }
            else if (str[i] == ']') {
                if (S.empty() || S.top() != '[') {
                    break;
                }
                S.pop();
            }
            i++;
        }
        if (S.empty() && i == str.npos)
            cout << "yes\n";
        else {
            cout << "no\n";
        }
    }
    return 0;
}