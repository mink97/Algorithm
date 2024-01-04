#include <bits/stdc++.h>
using namespace std;

#define MAXNUM 1002;

int bino_coef(int n, int k) {
    int cache[MAXNUM][MAXNUM] = { 0, };
    for (int i = 1; i <= n; i++) {
        cache[i][0] = cache[i][i] = 1;
        if (k * 2 > n) k = n - k;
        for (int j = 1; j < i; j++) {
            if (j > k) break;
            cache[i][j] = (cache[i - 1][j - 1] + cache[i - 1][j]) % 10007;
        }
    }
    return cache[n][k];
}


int cache[MAXNUM][MAXNUM] = { 0, };

// 이항 계수 두번째 방법

/*
** times는 지금까지 주어진 기회, got은 선택한 횟수
** 이 함수의 의미는 times 번 동안 got 개를 선택하는 조합의 개수가 아니라,
** times 번까지 got 개를 선택했을 때, 최종적으로 n 번의 기회를 소진 시에 선택한 개수가 k 가 되는 경우의 수를 반환하는 함수
*/
int choose(int times, int got, int n, int k) {
    // **아래 조건을 변경하여 확장성을 고려할 수 있음.
    // 주어진 기회를 다 사용했을 때, k번만큼 선택을 했으면 1, 그렇지 않으면 0 리턴
    if (times == n)
        return got == k;

    if (cache[times][got] != -1)
        return cache[times][got];

    // 다음 기회에서 선택을 한 경우와 선택을 안 한 경우를 더함.
    cache[times][got] = choose(times + 1, got, n, k) + choose(times + 1, got + 1, n, k);
    return cache[times][got];
}

int bino_coef2(int n, int k) {
    if (k > n) return 0;
    for (int i = 0; i < n + 1; i++) {
        fill(cache[i], cache[i] + n + 1; -1);
    }
    return choose(0, 0, n, k);
}