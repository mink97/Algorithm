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
	int arr[4];
	for (int i = 0; i < 3; ++i) {
		cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
		switch (arr[0] + arr[1] + arr[2] + arr[3])
		{
		case 0:
			cout << "D";
			break;
		case 1:
			cout << "C";
			break;
		case 2:
			cout << "B";
			break;
		case 3:
			cout << "A";
			break;
		case 4:
			cout << "E";
			break;
		default:
			break;
		}
		cout << "\n";
	}
}
