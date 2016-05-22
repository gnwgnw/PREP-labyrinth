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

	return newDirection;
}

void Runner::handleNewDirection(const Direction& direction){
	if (direction == lastChoice){
		oneWayStepCount++;
	} else {
		oneWayStepCount = 0;
	}

	auto i = find(dirs.begin(), dirs.end(), direction);
	dirs.erase(i);
	dirs.insert(dirs.end(), direction);

	x += (direction == Direction::RIGHT) - (direction == Direction::LEFT);
	y += (direction == Direction::DOWN)  - (direction == Direction::UP);

	lastChoice = direction;
}

Direction Runner::chooseDirection(const Cell& cell) const{
	for (auto a: dirs){
		if (!cell.getDirectionState(a)) return a;
	}

	return cell.getBackDirection();
}