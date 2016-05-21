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

	if (c.isDeadlock()){
		lastChoice = c.getBackDirection();
		history.pop();
		isForwardDirection = false;
	} else {
		while (c.getDirectionState(lastChoice)){
			// lastChoice = c.chooseNextDirection();
			lastChoice = Direction(rand() % 4);
		}
		isForwardDirection = true;
	}


	c.setDirectionState(lastChoice, true);
	// std::cout << c << '\n';

	return lastChoice;
}