#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int	arr[9] = {0, }, sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr + 9);
	sum -= 100;
	for (int i = 0; i < 8; i++) {
		for (int j = 8; j > i; j--) {
			if (arr[i] + arr[j] == sum) {
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j) continue;
					cout << arr[k] << "\n";
				}
				return (0);
			} else if (arr[i] + arr[j] < sum) break;
		}
	}
}
