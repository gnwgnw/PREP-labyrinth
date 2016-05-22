//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"

Cell :: Cell()
{
    left = SAFE;
    right = SAFE;
    up = SAFE;
    down = SAFE;
}
Cell :: Cell(const Cell& c)
{
	left = c.left;
	right = c.right;
	up = c.up;
	down = c.down;
}

Direction Runner::step()
{
    if(!path.size())
    {
        Cell c;
        path.push(c);
    }

	if ((current_status.up == BlockType::FREE || current_status.up == BlockType::EXIT) && path.top().up == SAFE)
	{
		Cell c1 = path.top();
		Cell c2;
		c1.up = FROM;
		c2.down = FROM;
		path.pop();
		path.push(c1);
		path.push(c2);
		return Direction::UP;
	}
	if ((current_status.left == BlockType::FREE || current_status.left == BlockType::EXIT) && path.top().left == SAFE)
	{
		Cell c1 = path.top();
		Cell c2;
		c1.left = FROM;
		c2.right = FROM;
		path.pop();
		path.push(c1);
		path.push(c2);
		return Direction::LEFT;
	}
	if ((current_status.down == BlockType::FREE || current_status.down == BlockType::EXIT) && path.top().down == SAFE)
	{
		Cell c1 = path.top();
		Cell c2;
		c1.down = FROM;
		c2.up = FROM;
		path.pop();
		path.push(c1);
		path.push(c2);
		return Direction::DOWN;
	}
	if ((current_status.right == BlockType::FREE || current_status.right == BlockType::EXIT) && path.top().right == SAFE)
	{
		Cell c1 = path.top();
		Cell c2;
		c1.right = FROM;
		c2.left = FROM;
		path.pop();
		path.push(c1);
		path.push(c2);
		return Direction::RIGHT;
	}



	if ((current_status.up == BlockType::FREE || current_status.up == BlockType::EXIT) && path.top().up != WALL)
	{
		path.pop();
		Cell c1 = path.top();
		c1.down = WALL;
		path.pop();
		path.push(c1);
		return Direction::UP;
	}
	if ((current_status.left == BlockType::FREE || current_status.left == BlockType::EXIT) && path.top().left != WALL)
	{
		path.pop();
		Cell c1 = path.top();
		c1.right = WALL;
		path.pop();
		path.push(c1);
		return Direction::LEFT;
	}
	if ((current_status.down == BlockType::FREE || current_status.down == BlockType::EXIT) && path.top().down != WALL)
	{
		path.pop();
		Cell c1 = path.top();
		c1.up = WALL;
		path.pop();
		path.push(c1);
		return Direction::DOWN;
	}
	if ((current_status.right == BlockType::FREE || current_status.right == BlockType::EXIT) && path.top().right != WALL)
	{
		path.pop();
		Cell c1 = path.top();
		c1.left = WALL;
		path.pop();
		path.push(c1);
		return Direction::RIGHT;
	}




}
