//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"

#include <iostream>
using namespace std;

Direction Runner::step(){
	if (isForwardDirection) {
		Cell currCell = Cell(current_status, lastChoice);
		history.push(currCell);
	}

	Cell& c = history.top();

	if (c.isDeadlock()){
		history.pop();
		isForwardDirection = false;
	} else {
		isForwardDirection = true;
	}

	lastChoice = chooseDirection(c);
	c.setDirectionState(lastChoice, true);

	return lastChoice;
}

Direction Runner::chooseDirection(const Cell& cell) const{
	Direction dirs[] = { 
						Direction::RIGHT,
						Direction::LEFT,
						Direction::DOWN, 
						Direction::UP,
						};

	for (auto a: dirs){
		if (!cell.getDirectionState(a)) return a;
	}

	return cell.getBackDirection();
}