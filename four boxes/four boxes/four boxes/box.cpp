#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int findMax(int ary[4][4]);
int main(void) {
	int ary[4][4] = { 0 };
	int maxX, maxY, count = 0;
	for (int i = 0; i < 4; i++) {
		std::cin >> ary[i][0] >> ary[i][1] >> ary[i][2] >> ary[i][3];
		std::cin.ignore(1, ',');
	}
	maxX = findMax(ary);
	maxY = maxX;
	std::vector < std::vector <int>> boxes(maxY+1, std::vector<int>(maxX+1));
	for (int i = 0; i < maxY; i++) {
		boxes[i].assign(boxes[i].size(), 0);
	}
	for (int num = 0; num < 4; num++) {
		for (int y = ary[num][1]; y < ary[num][3]; y++) {
			for (int x = ary[num][0]; x < ary[num][2]; x++) {
				boxes[y][x]++;
			}
		}
	}
	for (int y = 0; y < maxY; y++) {
		for (int x = 0; x < maxX; x++) {
			if (boxes[y][x] > 0)
				count++;
		}
	}
	std::cout << "Result : " << count << std::endl;
	return 0;
}
int findMax(int ary[4][4]) {
	std::vector <int> st;
	for (int i = 0; i < 4; i++) {
		int max = *std::max_element(ary[i], ary[i] + 4);
		st.push_back(max);
	}
	int max = *std::max_element(st.begin(), st.end());
	return max;
}