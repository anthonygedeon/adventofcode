#include <cctype>
#include <cmath>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <string_view>
#include <vector>
#include <sstream>

enum class Direction {
	north = 0, east, south, west
};

class Navigator {
public:
	Direction move_right() {
		m_turn++;
		return m_compass[m_turn % m_compass.size()];
	}

	Direction move_left() {
		m_turn--;
		if (m_turn < 0) {
			m_turn = static_cast<int>(m_compass.size() - 1);
		}
		return m_compass[m_turn % m_compass.size()];
	}

private:
	int m_turn = 0;

	std::vector<Direction> m_compass = { Direction::north, Direction::east, Direction::south, Direction::west };
};


struct position {
	int x;
	int y;

	auto manhatten_distance(position other) {
		return std::abs(x - other.x) + std::abs(y - other.y);
	}

	auto is_same(position other) {
		return x == other.x && y == other.y;
	}
};


int calculate_moves(std::string_view movements, std::string::size_type position) {
	std::string moves{ "" };
	for (size_t i = position + 1; std::isdigit(movements[i]); i++) {
		moves += movements[i];
	}
	return std::stoi(moves);
}

int part_1(std::string_view movements) {
	position pos{ 0, 0 };

	int move;
	Navigator nav{};
	for (std::string::size_type i{ 0 }; i < movements.size(); i++) {
		switch (movements[i]) {
			case 'R': {
				move = calculate_moves(movements, i);
				switch(nav.move_right()) {
					case Direction::north:
						pos.y += move;
						break;
					case Direction::east:
						pos.x += move;
						break;
					case Direction::south:
						pos.y -= move;
						break;
					case Direction::west:
						pos.x -= move;
						break;
				}
				break;
			}
			case 'L':
				move = calculate_moves(movements, i);
				switch(nav.move_left()) {
					case Direction::north:
						pos.y += move;
						break;
					case Direction::east:
						pos.x += move;
						break;
					case Direction::south:
						pos.y -= move;
						break;
					case Direction::west:
						pos.x -= move;
						break;
				}
				break;
		}
	}
	
	return pos.manhatten_distance({0, 0});
}

int part_2(std::string_view instructions) {
	position pos{0, 0};
	std::vector<position> locations;

	int move;
	Navigator nav{};
	for (std::string::size_type i{ 0 }; i < instructions.size(); i++) {
		switch (instructions[i]) {
			case 'R': 
				move = calculate_moves(instructions, i);
				switch(nav.move_right()) {
					case Direction::north:
						for (int i = 0; i < move; i++) {
							pos.y++;
							locations.push_back(pos);
						}
						break;
					case Direction::east:
						for (int i = 0; i < move; i++) {
							pos.x++;
							locations.push_back(pos);
						}
						break;
					case Direction::south:
						for (int i = 0; i < move; i++) {
							pos.y--;
							locations.push_back(pos);
						}
						break;
					case Direction::west:
						for (int i = 0; i < move; i++) {
							pos.x--;
							locations.push_back(pos);
						}
						break;
				}
				break;
			case 'L':
				move = calculate_moves(instructions, i);
				switch(nav.move_left()) {
					case Direction::north:
						for (int i = 0; i < move; i++) {
							pos.y++;
							locations.push_back(pos);
						}
						break;
					case Direction::east:
						for (int i = 0; i < move; i++) {
							pos.x++;
							locations.push_back(pos);
						}
						break;
					case Direction::south:
						for (int i = 0; i < move; i++) {
							pos.y--;
							locations.push_back(pos);
						}
						break;
					case Direction::west:
						for (int i = 0; i < move; i++) {
							pos.x--;
							locations.push_back(pos);
						}
						break;
				}
				break;
		}
	}	

	for (int i = 0; i < locations.size(); i++) {
		for (int j = i + 1; j < locations.size(); j++) {
			if (locations[i].is_same(locations[j])) {
				return locations[i].manhatten_distance({0,0});
			}
		}
	}

	return 0;
}

int main() {
	std::ifstream inf{ "input.txt" };
	if (!inf) {
		std::cerr << "Error: cannot open input.txt";
	}

	std::stringstream buffer{};
	buffer << inf.rdbuf();
	std::cout << "Part 1: " << part_1(buffer.str()) << '\n';
	std::cout << "Part 2: " << part_2(buffer.str()) << '\n';

	return 0;
}
