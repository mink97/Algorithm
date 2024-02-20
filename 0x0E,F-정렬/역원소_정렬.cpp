#include <bits/stdc++.h>
using namespace std;
int N;
long long arr[100005];

long long reverse(long long num) {
    long long tmp = 0;
    while (num) {
        tmp = tmp * 10 + num % 10;
        num /= 10;
    }
    return tmp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        long long num;
        cin >> num;
        arr[i] = reverse(num);
    }
    sort(arr, arr + N);
    for (int i = 0; i < N; i++) {
        cout << arr[i] << '\n';
    }
    return 0;
}