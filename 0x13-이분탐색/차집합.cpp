#include <bits/stdc++.h>
using namespace std;
int A[500005];
int B[500005];
int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A, A + N);
    for (int i = 0; i < M; i++) cin >> B[i];
    sort(B, B + M);
    vector<int> vec;
    for (int i = 0; i < N; i++) {
        if (binary_search(B, B + M, A[i])) continue;
        vec.push_back(A[i]);
    }
    cout << vec.size() << '\n';
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << ' ';
    }
    return 0;
}