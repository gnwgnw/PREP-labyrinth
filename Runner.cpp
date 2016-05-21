//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"

// #include <iostream>
using namespace std;

Runner::Runner(){
	isForwardDirection = true;
	srand(time(NULL));
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

	Direction newDirection = lastChoice;

	if (c.isDeadlock()){
		newDirection = c.getBackDirection();
		history.pop();
		isForwardDirection = false;
	} else {
		if (oneDirectionStepCount > 600){
			if (c.freeDirectionCount() > 1){
				newDirection = c.chooseNextDirection();
			}
		}

		while (c.getDirectionState(newDirection)){
			newDirection = Direction(rand() % 4);
			oneDirectionStepCount = 0;
		}
		// newDirection = c.chooseNextDirection();
		isForwardDirection = true;
		oneDirectionStepCount++;
	}

	lastChoice = newDirection;
	c.setDirectionState(lastChoice, true);
	// std::cout << c << '\n';

	return lastChoice;
}