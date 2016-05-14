//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"

// Work with Cell
Cell createCell(const Status& state, const Direction& prevStep){
	Cell cell;

    cell.prevStep = prevStep;
    
    cell.leftDone  = cell.state.left == BlockType::WALL;
    cell.rightDone = cell.state.right == BlockType::WALL;
    cell.downDone  = cell.state.down == BlockType::WALL;
    cell.upDone   = cell.state.up == BlockType::WALL;

    cell.state = state;

    return cell;
}

Cell createCell(const Status& state){
	return createCell(state, Direction::UP);
}

bool isDeadlock(const Cell& cell){
	return cell.upDone && cell.downDone && cell.leftDone && cell.rightDone;
}


inline Direction getOppositeDirection(const Direction& direction){
	switch (direction){
		case Direction::UP:    return Direction::DOWN;
		case Direction::DOWN:  return Direction::UP;
		case Direction::LEFT:  return Direction::RIGHT;
		case Direction::RIGHT: return Direction::LEFT;
	}
}
        
// Runner Members
Runner::Runner(){
	isForwardDirection = true;
}

Direction Runner::step(){

}