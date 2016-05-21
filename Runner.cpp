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
		if (oneDirectionStepCount < 194){
			do {
				newDirection = Direction(rand() % 4);
			} while (c.getDirectionState(newDirection));
		} else {//if (c.freeDirectionCount() < 2){
			newDirection = c.chooseNextDirection();
		}
		isForwardDirection = true;
	}

	if (lastChoice != newDirection){
		oneDirectionStepCount = 0;
	} else {
		oneDirectionStepCount++;
	}
	lastChoice = newDirection;
	c.setDirectionState(lastChoice, true);
	// std::cout << c << '\n';

	return lastChoice;
}