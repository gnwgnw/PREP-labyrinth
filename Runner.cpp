//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"
#include <vector>
#include <cstdlib>
#include "utils.hpp"


Direction Runner::step() {

	int get = 0;
	if (current_status.up != BlockType::WALL) ++get;
	if (current_status.down != BlockType::WALL) ++get;
	if (current_status.left != BlockType::WALL) ++get;
	if (current_status.right != BlockType::WALL) ++get;

			
	if (deadend && get > 2) {
			if (prev == Direction::RIGHT) {
				if (map[i][j-1] == 1) map[i][j-1] = 2;
				else map[i][j-1] = 1;
				deadend = false;
			}

			if (prev == Direction::LEFT) {
				if (map[i][j+1] == 1) map[i][j+1] = 2;
				else map[i][j+1] = 1;
				deadend = false;
			}

			if (prev == Direction::DOWN) {
				if (map[i-1][j] == 1) map[i-1][j] = 2;
				else map[i-1][j] = 1;
				deadend = false;
			}

			if (prev == Direction::UP) {
				if (map[i+1][j] == 1) map[i+1][j] = 2;
				else map[i+1][j] = 1;
				deadend = false;
			}
	}



	if (get == 1) deadend = true;
	if (get <= 2) {
		switch(prev) {
			case(Direction::LEFT):
				if (current_status.up != BlockType::WALL) {
					--i;
					return (prev = Direction::UP);
				}
				else if (current_status.left != BlockType::WALL) {
					--j;
					return (prev = Direction::LEFT);
				}
				else if (current_status.down != BlockType::WALL) {
					++i;
					return (prev = Direction::DOWN);
				}
				else {
					++j;
					return (prev = Direction::RIGHT);
				}

			case(Direction::RIGHT):
				if (current_status.down != BlockType::WALL) {
					++i;
					return (prev = Direction::DOWN);
				}
				else if (current_status.right != BlockType::WALL) {
					++j;
					return (prev = Direction::RIGHT);
				}
				else if (current_status.up != BlockType::WALL) {
					--i;
					return (prev = Direction::UP);
				}
				else {
					--j;
					return (prev = Direction::LEFT);
				}

			case(Direction::UP):
				if (current_status.right != BlockType::WALL) {
					++j;
					return (prev = Direction::RIGHT);
				}
				else if (current_status.up != BlockType::WALL) {
					--i;
					return (prev = Direction::UP);
				}
				else if (current_status.left != BlockType::WALL) {
					--j;
					return (prev = Direction::LEFT);
				}
				else {
					return (prev = Direction::DOWN);
					++i;
				}

			case(Direction::DOWN):
				if (current_status.left != BlockType::WALL) {
					--j;
					return (prev = Direction::LEFT);
				}
				else if (current_status.down != BlockType::WALL) {
					++i;
					return (prev = Direction::DOWN);
				}
				else if (current_status.right != BlockType::WALL) {
					++j;
					return (prev = Direction::RIGHT);
				}
				else {
					--i;
					return (prev = Direction::UP);
				}

		}
	}
			
	if (get > 2) {
		if (current_status.up != BlockType::WALL 
							&& map[i-1][j] == 0) {
			map[i-1][j] = 1;
			--i;
			return (prev = Direction::UP);
		}
		
		if (current_status.down != BlockType::WALL
							&& map[i+1][j] == 0) {
			map[i+1][j] = 1;
			++i;
			return (prev = Direction::DOWN);
		}

		if (current_status.left != BlockType::WALL
							&& map[i][j-1] == 0) {
			map[i][j-1] = 1;
			--j;
			return (prev = Direction::LEFT);
		}

		if (current_status.right != BlockType::WALL
							&& map[i][j+1] == 0) {
			map[i][j+1] = 1;
			++j;
			return (prev = Direction::RIGHT);
		}

		if (current_status.up != BlockType::WALL 
							&& map[i-1][j] == 1) {
			map[i-1][j] = 2;
			--i;
			return (prev = Direction::UP);
		}
		
		if (current_status.down != BlockType::WALL
							&& map[i+1][j] == 1) {
			map[i+1][j] = 2;
			++i;
			return (prev = Direction::DOWN);
		}

		if (current_status.left != BlockType::WALL
							&& map[i][j-1] == 1) {
			map[i][j-1] = 2;
			--j;
			return (prev = Direction::LEFT);
		}

		if (current_status.right != BlockType::WALL
							&& map[i][j+1] == 1) {
			map[i][j+1] = 2;
			++j;
			return (prev = Direction::RIGHT);
		}
	}
	return prev;
}
