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
Cell::Cell(const Status& status, const Direction& prevDirection){
	state = status;
    prevStep = prevDirection;
    backDirection = getOppositeDirection(prevDirection);

    upDone    = state.up == BlockType::WALL;
    downDone  = state.down == BlockType::WALL;
    leftDone  = state.left == BlockType::WALL;
    rightDone = state.right == BlockType::WALL;

    setDirectionState(backDirection, true);
}

// Public methods
bool Cell::isDeadlock() const{
	return !isNearExit() && upDone && downDone && leftDone && rightDone;
}

Direction Cell::getBackDirection() const{
	return backDirection;
}

bool Cell::isNearExit() const{
	return state.up == BlockType::EXIT    ||
		   state.down == BlockType::EXIT  ||
		   state.right == BlockType::EXIT ||
		   state.left == BlockType::EXIT;
}

bool Cell::getDirectionState(const Direction& direction) const{
	if (isNearExit()){
		switch (direction){
			case Direction::UP    : return state.up    != BlockType::EXIT;
			case Direction::DOWN  : return state.down  != BlockType::EXIT;
			case Direction::LEFT  : return state.left  != BlockType::EXIT;
			case Direction::RIGHT : return state.right != BlockType::EXIT;
		}
	} else {
		switch (direction){
			case Direction::UP    : return upDone;
			case Direction::DOWN  : return downDone;
			case Direction::LEFT  : return leftDone;
			case Direction::RIGHT : return rightDone;
		}
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

Direction Cell::getPrevDirection() const{
	return prevStep;
}

// Other functions
std::ostream& operator<<(std::ostream& s, const Cell& c){
	s << " C  | " << " " << (int)c.state.up << "  |  " << c.upDone << "  | ";
	s << "\n";

	s << " e  | " << (int)c.state.left << " " << (int)c.state.right << " | " << c.leftDone << " " << c.rightDone << " | ";
	s << "Prev: " << (int)c.prevStep << "  " << "Deadlock: " << c.isDeadlock() << "  ";
	s << "\n";

	s << " ll | " << " " << (int)c.state.down << "  |  " << c.downDone << "  | ";
	s << "Back: " << (int)c.backDirection << "  ";
	// s << "\n";

	return s;
}