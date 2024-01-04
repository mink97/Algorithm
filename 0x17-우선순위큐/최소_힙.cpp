#include <bits/stdc++.h>
using namespace std;

int heap[100005];
int sz = 0; // heap에 들어있는 원소의 수

void push(int x) {
    heap[++sz] = x;
    int i = sz;
    while (i != 1) {
        int pa = i / 2;
        if (heap[pa] > heap[i]) {
            swap(heap[pa], heap[i]);
            i = pa;
        }
        else break;
    }
}

int top() {
    return heap[1];
}

void pop() {
    heap[1] = heap[sz--];
    int i = 1;
    while (i * 2 <= sz) {
        int ch1 = i * 2, ch2 = i * 2 + 1;
        int min_child = ch1;
        if (ch2 <= sz && heap[ch2] < heap[ch1]) {
            min_child = ch2;
        }
        if (heap[i] < heap[min_child]) break;
        swap(heap[i], heap[min_child]);
        i = min_child;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int in;
        cin >> in;
        if (in == 0) {
            if (sz == 0) {
                cout << 0 << '\n';
                continue;
            }
            cout << top() << "\n";
            pop();
        }
        else {
            push(in);
        }
    }
    return 0;
}