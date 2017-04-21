//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"
#include <vector>
#include <cstdlib>
#include "utils.hpp"

using namespace std;

Direction Runner::step() {
	
	static Direction look = Direction::DOWN;

	switch(look) {
		
		case(Direction::UP):

			if (current_status.right != BlockType::WALL) {
				look = Direction::RIGHT;
				return look;

			} else {
				if(current_status.up != BlockType::WALL)
					return look;

				else {
					if(current_status.left != BlockType::WALL) {
						look = Direction::LEFT;
						return look;
					}

					else {
						look = Direction::DOWN;
						return look;
					}
				}
			}

		case(Direction::DOWN):

			if (current_status.left != BlockType::WALL) {
				look = Direction::LEFT;
				return look;

			} else {
				if(current_status.down != BlockType::WALL)
					return look;

				else {
					if(current_status.right != BlockType::WALL) {
						look = Direction::RIGHT;
						return look;
					}

					else {
						look = Direction::UP;
						return look;
					}
				}
			}
	
		case(Direction::LEFT):

			if (current_status.up != BlockType::WALL) {
				look = Direction::UP;
				return look;

			} else {
				if(current_status.left != BlockType::WALL)
					return look;

				else {
					if(current_status.down != BlockType::WALL) {
						look = Direction::DOWN;
						return look;
					}

					else {
						look = Direction::RIGHT;
						return look;
					}
				}
			}
	
		case(Direction::RIGHT):

			if (current_status.down != BlockType::WALL) {
				look = Direction::DOWN;
				return look;

			} else {
				if(current_status.right != BlockType::WALL)
					return look;

				else {
					if(current_status.up != BlockType::WALL) {
						look = Direction::UP;
						return look;
					}

					else {
						look = Direction::LEFT;
						return look;
					}
				}
			}

	}
	return Direction::UP;

}
