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
	int	sum = 0, min = 100, tmp;
	for (int i = 0; i < 7; i++) {
		cin >> tmp;
		if (tmp % 2 == 1) {
			sum += tmp;
			if (min > tmp)
				min = tmp;
		}
	}
	if (sum == 0) {
		cout << -1;
	} else {
		cout << sum << "\n" << min;
	}
}
