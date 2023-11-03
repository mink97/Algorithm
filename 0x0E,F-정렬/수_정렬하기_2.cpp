#include <bits/stdc++.h>
using namespace std;
int arr[1000001];
int tmp[1000001];

void merge(int st, int en) {
    int mid = (st + en) / 2;
    int idxa = st, idxb = mid;
    for (int i = st; i < en; i++) {
        if (idxa == mid) tmp[i] = arr[idxb++];
        else if (idxb == en) tmp[i] = arr[idxa++];
        else if (arr[idxa] <= arr[idxb]) tmp[i] = arr[idxa++];
        else tmp[i] = arr[idxb++];
    }
    for (int i = st; i < en; i++) {
        // cout << tmp[st + i] << "\n";
        arr[i] = tmp[i];
    }
}

// arr[st:en]을 정렬하고 싶다.
void merge_sort(int st, int en) {
    if (en <= st + 1) return; // 길이 1인 경우
    int mid = (st + en) / 2;
    merge_sort(st, mid); // arr[st:mid]을 정렬한다.
    merge_sort(mid, en); // arr[mid:en]을 정렬한다.
    merge(st, en); // arr[st:mid]와 arr[mid:en]을 합친다.
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    merge_sort(0, n);
    for (int i = 0; i < n; i++) cout << arr[i] << '\n';
    return 0;
}