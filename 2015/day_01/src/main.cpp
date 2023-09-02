#include <fstream>
#include <iostream>
#include <string_view>
#include <numeric>
#include <sstream>

std::size_t part_1(std::string_view tokens);
std::size_t part_2(std::string_view tokens);

int main() {
	std::ifstream inf{ "input.txt" };
	if (!inf) {
		std::cerr << "Error: cannot open input.txt";
	}

	std::stringstream buffer{};
	buffer << inf.rdbuf();

	std::size_t floors = part_1(buffer.str());
	std::size_t position = part_2(buffer.str());

	std::cout << "Part: 1 " << floors << " Part 2 " << position << '\n';
}

std::size_t part_1(std::string_view tokens) {
	return std::accumulate(tokens.begin(), tokens.end(), static_cast<std::size_t>(0), 
			[](char acc, char brace) {
				switch (brace) {
					case '(': acc += 1; break;
					case ')': acc -= 1; break;
					default: ;
				}
				return acc;
	});
}

std::size_t part_2(std::string_view tokens) {
	int pos = 0;
	std::size_t count = 0;
	for (char token : tokens) {
		count += 1;
		switch(token) {
			case '(': pos += 1; break;
			case ')': pos -= 1; break;
			default: ;
		}
		if (pos == -1) {
			break;
		}
	}
	return count;
}

