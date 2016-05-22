//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"

#include <iostream>
using namespace std;

inline int max(int a, int b){
	return a > b ? a : b;
}

Direction Runner::step(){
	if (isForwardDirection) {
		Cell currCell = Cell(current_status, lastChoice);
		history.push(currCell);
	}

	Cell& c = history.top();
	Direction newDirection;

	if (history.size() > 662500 || oneWayStepCount > 500000){
		for (auto a: dirs){
			c.setDirectionState(a, true);
			// std::cout << "Go back " << history.size() << '\n';
		}
	}

	if (c.isDeadlock()){
		newDirection = c.getBackDirection();
		history.pop();
		isForwardDirection = false;
	} else {
		isForwardDirection = true;
		newDirection = chooseDirection(c);
	}

	c.setDirectionState(newDirection, true);
	handleNewDirection(newDirection);


	if (c.isNearExit()){
		std::cout << "Minimal step count: " << history.size() + 1 << '\n';
	}

	return newDirection;
}

void Runner::handleNewDirection(const Direction& direction){
	if (direction == lastChoice){
		oneWayStepCount++;
	} else {
		oneWayStepCount = 0;
	}

	switch(direction){
		case Direction::UP:
			upCount++;
			break;
		case Direction::DOWN:
			downCount++;
			break;
		case Direction::LEFT:
			leftCount++;
			break;
		case Direction::RIGHT:
			rightCount++;
			break;
	}

	x += (direction == Direction::RIGHT) - (direction == Direction::LEFT);
	y += (direction == Direction::DOWN)  - (direction == Direction::UP);

	lastChoice = direction;

	stepCount++;
}

Direction Runner::chooseDirection(const Cell& cell) const{
	// if (x < y){
	// 	if (!cell.getDirectionState(Direction::DOWN)) return Direction::DOWN;
	// } else if (y < x){
	// 	if (!cell.getDirectionState(Direction::RIGHT)) return Direction::RIGHT;
	// }

	for (auto a: dirs){
		if (!cell.getDirectionState(a)) return a;
	}

	return cell.getBackDirection();
}