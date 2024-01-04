#include <bits/stdc++.h>
using namespace std;

vector<int> vec, vec_two;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, max = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        vec.push_back(k);
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vec_two.push_back(vec[i] + vec[j]);
        }
    }
    sort(vec_two.begin(), vec_two.end());
    for (int j = n - 1; j > 0; j--) {
        for (int i = 0; i < j; i++) {
            int num = vec[j] - vec[i];
            if (binary_search(vec_two.begin(), vec_two.end(), num)) {
                cout << vec[j];
                return 0;
            }
        }
    }
    return 0;
}