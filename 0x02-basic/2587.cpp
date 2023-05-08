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
	int	in[5] = {0, }, sum = 0;
	for (int i = 0; i < 5; i++) {
		cin >> in[i];
		sum += in[i];
	}
	sort(in, in + 5);
	cout << sum / 5 << "\n";
	cout << in[2];
}
