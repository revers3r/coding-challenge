#include <iostream>
#include <regex>
#include <vector>
#include <string>

unsigned int slump(std::string data);
unsigned int slimp(std::string data);
unsigned int slurpy(std::string& data);
int main(void) {
	int num, i;
	std::string data2;
	std::vector<std::string> data1;
	std::cin >> num;
	for (i = 0; i < num; i++) {
		std::cin >> data2;
		data1.push_back(data2);
	}
	std::cout << "SLURPYS OUTPUT" << std::endl;
	for (auto dt : data1) {
		if (slurpy(dt))
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;
	}
	std::cout << "END OF OUTPUT" << std::endl;
	return 0;
}
unsigned int slump(std::string data) {
	std::regex rgx("^[DE]F+((.*)G)");
	std::cmatch mchs;
	if (std::regex_match(data.c_str(), mchs, rgx)) {
		if (!(mchs[2].str().empty())) {
			return slump(mchs[1]);
		}
		else {
			return 1;
		}
	}
	return 0;
}
unsigned int slimp(std::string data) {
	std::regex rgx_for_first("(AB(.+)C)");
	std::regex rgx_for_second("(A(.+)C)");
	std::cmatch mchs;

	if (data.c_str()[0] == 'A' && data.c_str()[1] == 'H') return 1;
	if (std::regex_match(data.c_str(), mchs, rgx_for_first)) {
		if (!(mchs[2].str().empty())) {
			if (slimp(mchs[2]))
				return 1;
			else
				return 0;
		}
	}
	else if (std::regex_match(data.c_str(), mchs, rgx_for_second)) {
		if (!(mchs[2].str().empty())) {
			if (slump(mchs[2]))
				return 1;
			else
				return 0;
		}
	}
	return 0;
}
unsigned int slurpy(std::string& data) {
	std::regex rgx_first("(AB(.+)C)");
	std::regex rgx_second("(A(.+)C)");
	std::smatch match;
	if (data.c_str()[0] == 'A' && data.c_str()[1] == 'H') {
		if (slump(data.c_str() + 2)) {
			return 1;
		}
	}
	else if (std::regex_search(data, match, rgx_first)) {
		if (slimp(match[1])) {
			if (slump(data.c_str() + match[1].length())) {
				return 1;
			}
		}
	}
	else if (std::regex_search(data, match, rgx_second)) {
		if (slimp(match[1])) {
			if (slump(data.c_str() + match[1].length())) {
				return 1;
			}
		}
	}
	return 0;
}