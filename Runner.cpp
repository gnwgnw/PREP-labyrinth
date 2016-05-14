//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"

#include <iostream>
using namespace std;

Runner::Runner(){
	isForwardDirection = true;

	x = 0;
	y = 0;
}

Direction Runner::step(){
	if (isForwardDirection) {
		if (history.size()){
			Cell currCell = Cell(current_status, lastChoice);
			history.push(currCell);
		} else {
			Cell currCell = Cell(current_status);
			history.push(currCell);
		}
	}

	Cell& c = history.top();

	// std::cout << "isForward: " << isForwardDirection << '\n';
	// std::cout << history.size() << "Before: \n" << c << "\n";
	
	lastChoice = c.chooseNextDirection();
	
	x = x - (lastChoice == Direction::LEFT) + (lastChoice == Direction::RIGHT);
	y = y - (lastChoice == Direction::UP) + (lastChoice == Direction::DOWN);


	if (c.isDeadlock() || checkForDeadlock(x, y)){
		history.pop();
		isForwardDirection = false;
		if (isForwardDirection){
			addDeadlock(x, y);
		}

	} else {
		isForwardDirection = true;
	}

	c.setDirectionState(lastChoice, true);
	// std::cout << history.size() << "After: \n" << c << "\n\n\n";

	return lastChoice;
}

bool Runner::checkForDeadlock(int x, int y) const{
	return std::find(deadlocks.cbegin(), deadlocks.cend(), std::make_pair(x, y)) != deadlocks.cend();
}

bool Runner::checkForDeadlock(const Direction& direction){
	int nx = x - (direction == Direction::LEFT) + (direction == Direction::RIGHT);
	int ny = y - (direction == Direction::UP) + (direction == Direction::DOWN);

	return checkForDeadlock(nx, ny);
}

void Runner::addDeadlock(int x, int y){
	deadlocks.push_back(std::make_pair(x, y));
}