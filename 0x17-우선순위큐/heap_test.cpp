#include <bits/stdc++.h>
using namespace std;

int heap[100005];
int sz = 0; // heap에 들어있는 원소의 수

void push(int x) {
    heap[++sz] = x;
    int i = sz;
    while (i / 2) {
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
    int ch1 = i * 2, ch2 = i * 2 + 1;
    while (ch1 <= sz) {
        if (ch1 == sz) {
            if (heap[ch1] < heap[i]) {
                swap(heap[ch1], heap[i]);
                i = ch1;
            }
            else break;
        }
        else {
            if (heap[ch1] > heap[ch2] && heap[i] > heap[ch2]) {
                swap(heap[i], heap[ch2]);
                i = ch2;
            }
            else if (heap[ch2] > heap[ch1] && heap[i] > heap[ch1]) {
                swap(heap[ch1], heap[i]);
                i = ch1;
            }
            else break;
        }
        ch1 = i * 2, ch2 = i * 2 + 1;
    }
}
void test() {
    push(10); push(2); push(5); push(9); // {10, 2, 5, 9}
    cout << top() << '\n'; // 2
    pop(); // {10, 5, 9}
    pop(); // {10, 9}
    cout << top() << '\n'; // 9
    push(5); push(15); // {10, 9, 5, 15}
    cout << top() << '\n'; // 5
    pop(); // {10, 9, 15}
    cout << top() << '\n'; // 9
}

int main() {
    test();
}