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
	int a, b, c;
	cin >> a >> b >> c;
	int d, e, f;
	d = max({a, b, c});
	e = min({a, b, c});
	f = a + b + c - d - e;
	if (d == e) {
		cout << 10000 + (1000 * d);
	} else if (d == f || f == e) {
		cout << 1000 + (100 * f);
	} else {
		cout << d * 100;
	}
}
