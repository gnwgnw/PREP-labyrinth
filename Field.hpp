//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_FIELD_HPP
#define LABYRINTH_FIELD_HPP

#include <vector>
#include <istream>
#include <iostream>

#include "Runner.hpp"
#include "utils.hpp"


using std::vector;
using namespace std;

class Field {
private:
	struct Position {
		size_t x;
		size_t y;
	};

	size_t tic_count = 0;
	bool done = false;

	vector<vector<BlockType>> field;
	Runner runner;

	Position current_position;

	void set_runner_current_status();

public:

	friend std::istream& operator>>(std::istream& is, Field& field);

	void tic();
	bool is_done();

	void result(std::ostream& os);
	void go(Direction d);
};

void Field::tic()
{
	current_position.x = 4;
	current_position.y = 4;
	go(Direction::DOWN);

	if (field.at(current_position.x - 1).at(current_position.y) == BlockType::EXIT)
		current_position.x--;
	if (field.at(current_position.x + 1).at(current_position.y) == BlockType::EXIT)
		current_position.x++;
	if (field.at(current_position.x).at(current_position.y - 1) == BlockType::EXIT)
		current_position.y--;
	if (field.at(current_position.x).at(current_position.y + 1) == BlockType::EXIT)
		current_position.y++;
	if (is_done())
	{
		cout << "VICTORY!!!!!!!!!!!!!!!!!!!!!\n\n";
		return;
	}
	return;

}

std::istream& operator >> (std::istream& is, BlockType& block_type)
{
	int h = 0;
	is >> h;
	switch (h)
	{
	case 0:
		block_type = BlockType::FREE;
		break;
	case 1:
		block_type = BlockType::WALL;
		break;
	case 2:
		block_type = BlockType::ENTER;
		break;
	case 3:
		block_type = BlockType::EXIT;
		break;
	}
	return is;
}

std::istream& operator >> (std::istream& is, Field& field)
{
	int a, b;
	BlockType k;
	is >> a >> b;
	for (int i = 0; i < a; i++)
	{
		vector<BlockType> v;
		field.field.push_back(v);
		for (int j = 0; j < b; j++)
		{
			is >> k;
			field.field[i].push_back(k);
		}
	}
	return is;
}

bool Field::is_done()
{
	if (field.at(current_position.x).at(current_position.y) == BlockType::EXIT) return true;
	else return false;
}

void Field::go(Direction d)
{
	if (is_done())
	{
		return;
	}

	cout << "x : " << current_position.x << "    y:  " << current_position.y << "\n";

	if (d == Direction::UP) current_position.x--;
	if (d == Direction::DOWN) current_position.x++;
	if (d == Direction::LEFT) current_position.y--;
	if (d == Direction::RIGHT) current_position.y++;


	if (field.at(current_position.x - 1).at(current_position.y) != BlockType::WALL && d != Direction::DOWN)
		go(Direction::UP);
	if (field.at(current_position.x + 1).at(current_position.y) != BlockType::WALL && d != Direction::UP)
		go(Direction::DOWN);
	if (field.at(current_position.x).at(current_position.y - 1) != BlockType::WALL && d != Direction::RIGHT)
		go(Direction::LEFT);
	if (field.at(current_position.x).at(current_position.y + 1) != BlockType::WALL && d != Direction::LEFT)
		go(Direction::RIGHT);
}

void Field::result(std::ostream& os)
{
	os << "x : " << current_position.x << "    y:  " << current_position.y << "\n";
}


#endif //LABYRINTH_FIELD_HPP
