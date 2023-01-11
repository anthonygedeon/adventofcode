#include "file.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iterator>
#include <optional>

namespace Token
{
	constexpr char open_paren  = '(';
	constexpr char close_paren = ')';
}

int main()
{
	auto contents { read_file("input.txt") };
	if (!contents.has_value()) return EXIT_FAILURE;
	
	int total_floors{};
	for (auto step : contents.value()) 
	{
		switch(step)
		{
			case Token::open_paren:
				total_floors += 1;
				break;
			case Token::close_paren:
				total_floors -= 1;
				break;
			default:
				break;
		}
	}
	
	std::cout << total_floors << '\n';

	return 0;
}

/// read the file from a given path
std::optional<std::string> read_file(std::string_view filename) 
{
	std::ifstream ifs { filename.data() };	
	if (!ifs) return {};
	// https://stackoverflow.com/a/116220/10930155	
	std::string contents { std::istreambuf_iterator<char> { ifs }, {} };
	return contents;
}
