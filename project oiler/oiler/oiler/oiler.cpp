#include <iostream>
#include <string>
#include <vector>

int main(void) {
	int sum = 0;
	bool exist;
	std::vector<int> vec;
	for (auto i = 0; i < 1000; i++) {
		if ((i % 3 == 0) || (i % 5 == 0)) {
			exist = std::find(vec.begin(), vec.end(), i) != vec.end();
			if (!exist) {
				sum += i;
				vec.push_back(i);
			}
		}
	}
	std::cout << "Result : " << sum << std::endl;
}