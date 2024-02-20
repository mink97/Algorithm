#include <bits/stdc++.h>
using namespace std;
int N, M;
unordered_map<string, string> m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string str, password;
        cin >> str >> password;
        m[str] = password;
    }
    for (int i = 0; i < M; i++) {
        string str;
        cin >> str;
        cout << m[str] << '\n';
    }
    return 0;
}