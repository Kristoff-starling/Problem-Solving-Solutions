#include<bits/stdc++.h>

void hanoi_tower(int size, int from, int to) {
	if (size == 0)
        return;
    int middle = 6 - from - to;
	hanoi_tower(size - 1, from, middle);
	std::cout << "Move From " << from << " To " << to << '\n';
	hanoi_tower(size - 1, middle, to);
}

int main() {
	int n;
	std::cin >> n;
	std::cout << ((1 << n) - 1) << '\n';
	hanoi_tower(n, 1, 3);
    return 0;
}