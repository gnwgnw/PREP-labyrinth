//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"

Direction Runner::step()
{
	Direction direction;

	Status status = current_status;
	if(square_number >= squares_on_field.size()) { 
		squares_on_field.resize(squares_on_field.size() + 1);
		squares_on_field[squares_on_field.size() - 1] = { 0, 0, 0, 0 };
	}

	if ((status.left != BlockType::WALL) && (status.left != BlockType::ENTER) && (squares_on_field[square_number].left == 0)) {
		direction = Direction::LEFT;
		squares_on_field[square_number].left = 1;
		square_number++;
		if (square_number >= squares_on_field.size()) {
			squares_on_field.resize(squares_on_field.size() + 1);
			squares_on_field[squares_on_field.size() - 1] = { 0, 0, 0, 0 };
		}
		squares_on_field[square_number].right = 1;
		return direction;
	}
	if ((status.up != BlockType::WALL) && (status.up != BlockType::ENTER) && (squares_on_field[square_number].up == 0)) {
		direction = Direction::UP;
		squares_on_field[square_number].up = 1;
		square_number++;
		if (square_number >= squares_on_field.size()) {
			squares_on_field.resize(squares_on_field.size() + 1);
			squares_on_field[squares_on_field.size() - 1] = { 0, 0, 0, 0 };
		}
		squares_on_field[square_number].down = 1;
		return direction;
	}
	if ((status.right != BlockType::WALL) && (status.right != BlockType::ENTER) && (squares_on_field[square_number].right == 0)) {
		direction = Direction::RIGHT;
		squares_on_field[square_number].right = 1;
		square_number++;
		if (square_number >= squares_on_field.size()) {
			squares_on_field.resize(squares_on_field.size() + 1);
			squares_on_field[squares_on_field.size() - 1] = { 0, 0, 0, 0 };
		}
		squares_on_field[square_number].left = 1;
		return direction;
	}
	if ((status.down != BlockType::WALL) && (status.down != BlockType::ENTER) && (squares_on_field[square_number].down == 0)) {
		direction = Direction::DOWN;
		squares_on_field[square_number].down = 1;
		square_number++;
		if (square_number >= squares_on_field.size()) {
			squares_on_field.resize(squares_on_field.size() + 1);
			squares_on_field[squares_on_field.size() - 1] = { 0, 0, 0, 0 };
		}
		squares_on_field[square_number].up = 1;
		return direction;
	}
	//если возвращаемся назад

	if ((status.left != BlockType::WALL) && (status.left != BlockType::ENTER) && (squares_on_field[square_number].left != 2)) {
		direction = Direction::LEFT;
		squares_on_field[square_number] = { 0, 0, 0, 0 };
		square_number--;
		squares_on_field[square_number].right = 2;
		return direction;
	}
	if ((status.up != BlockType::WALL) && (status.up != BlockType::ENTER) && (squares_on_field[square_number].up != 2)) {
		direction = Direction::UP;
		squares_on_field[square_number] = { 0, 0, 0, 0 };
		square_number--;
		squares_on_field[square_number].down = 2;
		return direction;
	}
	if ((status.right != BlockType::WALL) && (status.right != BlockType::ENTER) && (squares_on_field[square_number].right != 2)) {
		direction = Direction::RIGHT;
		squares_on_field[square_number] = { 0, 0, 0, 0 };
		square_number--;
		squares_on_field[square_number].left = 2;
		return direction;
	}
	if ((status.down != BlockType::WALL) && (status.down != BlockType::ENTER) && (squares_on_field[square_number].down != 2)) {
		direction = Direction::DOWN;
		squares_on_field[square_number] = { 0, 0, 0, 0 };
		square_number--;
		squares_on_field[square_number].up = 2;
		return direction;
	}
}
