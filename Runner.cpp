//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"

#include <iostream>
using namespace std;

Runner::Runner(){
	isForwardDirection = true;
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

	if (c.isDeadlock()){
		history.pop();
		isForwardDirection = false;

	} else {
		isForwardDirection = true;
	}
	c.setDirectionState(lastChoice, true);
	// std::cout << history.size() << "After: \n" << c << "\n\n\n";

	return lastChoice;
}