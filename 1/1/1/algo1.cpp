#include <iostream>
#include <string>
#include <vector>

unsigned int d_fn(int num);
int main(void) {
	std::vector<int> arr;
	unsigned int d_sum;
	bool exists;
	for (auto idx = 1; idx <= 5000; idx++) {
		d_sum = d_fn(idx);
		exists = std::find(std::begin(arr), std::end(arr), d_sum) != std::end(arr);
		if (!exists) {
			arr.push_back(d_sum);
		}
	}
	d_sum = 0;
	for (auto idx = 1; idx <= 5000; idx++) {
		exists = std::find(std::begin(arr), std::end(arr), idx) != std::end(arr);
		if (!exists) {
			d_sum += idx;
		}
	}
	std::cout << d_sum << std::endl;
}
unsigned int d_fn(int num) {
	std::string st;
	unsigned int d_sum;
	st = std::to_string(num);
	d_sum = num;
	for (auto i = 0; i < st.length(); i++) {
		d_sum += (int)(st[i] - 48);
	}
	return d_sum;
}