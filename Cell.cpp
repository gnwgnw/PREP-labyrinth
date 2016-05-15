//
// Created by ed_asriyan on 14.05.16.
//

#include "Cell.hpp"

// Local functions
Direction getOppositeDirection(const Direction& direction){
	switch (direction){
		case Direction::UP:    return Direction::DOWN;
		case Direction::DOWN:  return Direction::UP;
		case Direction::LEFT:  return Direction::RIGHT;
		case Direction::RIGHT: return Direction::LEFT;
	}
}

// Constructors & Destructors
Cell::Cell(){

}

Cell::Cell(const Status& status, const Direction& prevDirection)
: Cell(status){
    prevStep = prevDirection;
    backDirection = getOppositeDirection(prevStep);

    isStart = false;
    setDirectionState(backDirection, true);
}

Cell::Cell(const Status& status){
	state = status;

    upDone   = state.up == BlockType::WALL;
    downDone  = state.down == BlockType::WALL;
    leftDone  = state.left == BlockType::WALL;
    rightDone = state.right == BlockType::WALL;

    isStart = true;
}

// Public methods
bool Cell::isDeadlock() const{
	return upDone && downDone && leftDone && rightDone;
}

Direction Cell::getBackDirection() const{
	return backDirection;
}

bool Cell::getDirectionState(const Direction& direction) const{
	switch (direction){
		case Direction::UP    : return upDone;
		case Direction::DOWN  : return downDone;
		case Direction::LEFT  : return leftDone;
		case Direction::RIGHT : return rightDone;
	}
}

void Cell::setDirectionState(const Direction& direction, bool value){
	switch (direction){
		case Direction::UP: 
			upDone = value;
			break;
		case Direction::DOWN: 
			downDone = value;
			break;
		case Direction::LEFT:
			leftDone = value;
			break;
		case Direction::RIGHT:
			rightDone = value;
			break;
	}
}

Direction Cell::chooseNextDirection() const{
	if (state.up    == BlockType::EXIT) return Direction::UP;
	if (state.down  == BlockType::EXIT) return Direction::DOWN;
	if (state.left  == BlockType::EXIT) return Direction::LEFT;
	if (state.right == BlockType::EXIT) return Direction::RIGHT;

	// !!! Direction priority !!!
	if (!rightDone) return Direction::RIGHT;
	if (!downDone)  return Direction::DOWN;
	if (!upDone)    return Direction::UP;
	if (!leftDone)  return Direction::LEFT;

	return backDirection;
}

// Other functions
std::ostream& operator<<(std::ostream& s, const Cell& c){
	s << " C  | " << " " << (int)c.state.up << "  |  " << c.upDone << "  | ";
	s << "Next: " << (int)c.chooseNextDirection() << "  ";
	s << "\n";

	s << " e  | " << (int)c.state.left << " " << (int)c.state.right << " | " << c.leftDone << " " << c.rightDone << " | ";
	s << "Prev: " << (int)c.prevStep << "  " << "Deadlock: " << c.isDeadlock() << "  ";
	s << "\n";

	s << " ll | " << " " << (int)c.state.down << "  |  " << c.downDone << "  | ";
	s << "Back: " << (int)c.backDirection << "  ";
	// s << "\n";

	return s;
}