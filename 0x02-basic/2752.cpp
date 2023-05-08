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
	int	a, b, c;
	cin >> a >> b >> c;
	if (a > b) {
		if (b > c) {
			cout << c << ' ' << b << ' ' << a;
		} else if (c > a){
			cout << b << ' ' << a << ' ' << c;
		} else {
			cout << b << ' ' << c << ' ' << a;
		}
	} else {
		if (a > c) {
			cout << c << ' ' << a << ' ' << b;
		} else if (b > c) {
			cout << a << ' ' << c << ' ' << b;
		} else {
			cout << a << ' ' << b << ' ' << c;
		}
	}
}
