#include <iostream>

int	main() {
	int	N;
	int	X;

	std::cin >> N >> X;
	for (int i = 0; i < N; i++) {
		int	tmp;
		std::cin >> tmp;
		if (tmp < X)
			std::cout << tmp << " ";
	}
}
