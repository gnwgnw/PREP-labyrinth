//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"
#include "debug.hpp"


Runner::Runner(){
	isForwardDirection = true;

	x = 4;
	y = 3;
}

Direction Runner::step(){
	LOG(0, "Runner position: (", x, ", ", y, ")");
	LOG(1, "History size   : ", history.size());
	LOG(1, "Deadlocks size : ", deadlocks.size());

	// current cell must be at the top of history
	if (isForwardDirection) {
		LOG(1, "Direction: forward");

		// if forward direction it adds new Cell
		if (history.size()){
			Cell currCell = Cell(current_status, lastChoice);
			history.push(currCell);
		} else {
			Cell currCell = Cell(current_status);
			history.push(currCell);
		}
	} else {
		LOG(1, "Direction: backward");

		// if backward direction do nothing
		// current cell alredy at the top
	}


	// handling current cell
	Cell& c = history.top();
	LOG(0, c);
	
	// choose new direction
	Direction nextDirection;
	bool haveChoice = false;

	while (!haveChoice){
		if (c.isDeadlock()) {
			// if deadlock new direction is backward
			
			nextDirection = c.getBackDirection();
			haveChoice = true;

			history.pop();
			isForwardDirection = false;
		} else {
			// if not try to choose new forward direction

			nextDirection = c.chooseNextDirection();
			c.setDirectionState(nextDirection, true);
			LOG(2, "Cheking direction ", (int)nextDirection);

			haveChoice = !checkForDeadlock(nextDirection);
			isForwardDirection = true;
		}
	}

	if (c.isDeadlock()){
		addDeadlock(x, y);
	}

	// setting new state
	x = x - 2*(nextDirection == Direction::LEFT) + 2*(nextDirection == Direction::RIGHT);
	y = y - 1*(nextDirection == Direction::UP) + 1*(nextDirection == Direction::DOWN);
	lastChoice = nextDirection;

	LOG(0);
	return nextDirection;
}

bool Runner::checkForDeadlock(int x, int y) const{
	return std::find(deadlocks.crbegin(), deadlocks.crend(), std::make_pair(x, y)) != deadlocks.crend();
}

bool Runner::checkForDeadlock(const Direction& direction) const{
	int nx = x - 2*(direction == Direction::LEFT) + 2*(direction == Direction::RIGHT);
	int ny = y - (direction == Direction::UP) + (direction == Direction::DOWN);

	return checkForDeadlock(nx, ny);
}

void Runner::addDeadlock(int x, int y){
	deadlocks.push_back(std::make_pair(x, y));
}