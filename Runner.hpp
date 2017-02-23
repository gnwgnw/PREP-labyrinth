//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include "RunnerBase.hpp"
#include <stack>
#include <vector>

using namespace std;

bool flag = false;
int flag1 = 0;
stack<int> ch;

class Cell
{
public:
	bool left;
	bool right;
	bool up;
	bool down;

	Direction backStep;

	int kol;

	Cell()
	{
		left = false;
		right = false;
		up = false;
		down = false;
	}

	Cell(int i)
	{
		left = true;
		right = true;
		up = true;
		down = true;
	}

	Cell(const Cell&c)
	{
		left = c.left;
		right = c.right;
		up = c.up;
		down = c.down;
		backStep = c.backStep;
	}

	~Cell() {};

	void setStatus(Status& st)
	{
		kol = 0;
		if (st.up == BlockType::FREE || st.up == BlockType::EXIT || st.up == BlockType::ENTER) {
			up = true; kol++;
		}
		if (st.down == BlockType::FREE || st.down == BlockType::EXIT || st.down == BlockType::ENTER) { down = true; kol++; }
		if (st.left == BlockType::FREE || st.left == BlockType::EXIT || st.left == BlockType::ENTER) {
			left = true; kol++;
		}
		if (st.right == BlockType::FREE || st.right == BlockType::EXIT || st.right == BlockType::ENTER) {
			right = true; kol++;
		}

	}

	void setTrue()
	{
		left = true;
		right = true;
		up = true;
		down = true;
	}

};
Cell kost;


class Runner : public RunnerBase {
public:
	std::stack<Cell> path;
	std::stack<Cell> st;
	Cell b;
	Cell b1;
	Direction step();
	Direction back;
};

Direction Runner::step()
{
	Cell c;
	c.setStatus(current_status);
	if (path.size() && c.kol == 3 && flag)
	{
		flag = false;
		switch (b.backStep)
		{
		case Direction::LEFT:
			b.backStep = Direction::RIGHT;
			break;
		case Direction::RIGHT:
			b.backStep = Direction::LEFT;
			break;
		case Direction::UP:
			b.backStep = Direction::DOWN;
			break;
		case Direction::DOWN:
			b.backStep = Direction::UP;
			break;
		}


		if (c.up && !path.size() || c.up && path.top().backStep != Direction::UP && b.backStep != Direction::UP)
		{
			c.backStep = Direction::DOWN;
			c.up = false;
			path.push(c);
			return Direction::UP;
		}
		if (c.left && !path.size() || c.left && path.top().backStep != Direction::LEFT && b.backStep != Direction::LEFT)
		{
			c.backStep = Direction::RIGHT;
			c.left = false;
			path.push(c);
			return Direction::LEFT;
		}
		if (c.down && !path.size() || c.down && path.top().backStep != Direction::DOWN && b.backStep != Direction::DOWN)
		{
			c.backStep = Direction::UP;
			c.down = false;
			path.push(c);
			return Direction::DOWN;
		}
		if (c.right && !path.size() || c.right && path.top().backStep != Direction::RIGHT && b.backStep != Direction::RIGHT)
		{
			c.backStep = Direction::LEFT;
			c.right = false;
			path.push(c);
			return Direction::RIGHT;
		}

	}
	else {
		if (!path.size() && c.kol == 3 && flag)
		{
			flag = false;

			switch (b.backStep)
			{
			case Direction::LEFT:
				b.backStep = Direction::RIGHT;
				break;
			case Direction::RIGHT:
				b.backStep = Direction::LEFT;
				break;
			case Direction::UP:
				b.backStep = Direction::DOWN;
				break;
			case Direction::DOWN:
				b.backStep = Direction::UP;
				break;
			}
			path.push(b);

			if (c.up && !path.size() || c.up && b.backStep != Direction::UP)
			{
				c.backStep = Direction::DOWN;
				c.up = false;
				path.push(c);
				return Direction::UP;
			}
			if (c.left && !path.size() || c.left && b.backStep != Direction::LEFT)
			{
				c.backStep = Direction::RIGHT;
				c.left = false;
				path.push(c);
				return Direction::LEFT;
			}
			if (c.down && !path.size() || c.down && b.backStep != Direction::DOWN)
			{
				c.backStep = Direction::UP;
				c.down = false;
				path.push(c);
				return Direction::DOWN;
			}
			if (c.right && !path.size() || c.right && b.backStep != Direction::RIGHT)
			{
				c.backStep = Direction::LEFT;
				c.right = false;
				path.push(c);
				return Direction::RIGHT;
			}

		}

	}

	if (path.size() && c.kol == 4 && flag)
	{
		flag = false;
		if (flag1 == 0)
		{
			switch (b.backStep)
			{
			case Direction::LEFT:
				b.backStep = Direction::RIGHT;
				break;
			case Direction::RIGHT:
				b.backStep = Direction::LEFT;
				break;
			case Direction::UP:
				b.backStep = Direction::DOWN;
				break;
			case Direction::DOWN:
				b.backStep = Direction::UP;
				break;
			}
			st.push(b);
			ch.push(1);
			flag1 += 1;

			if (c.up && !path.size() || c.up && path.top().backStep != Direction::UP && b.backStep != Direction::UP && b1.backStep != Direction::UP)
			{
				c.backStep = Direction::DOWN;
				c.up = false;
				path.push(c);
				return Direction::UP;
			}
			if (c.left && !path.size() || c.left && path.top().backStep != Direction::LEFT && b.backStep != Direction::LEFT && b1.backStep != Direction::LEFT)
			{
				c.backStep = Direction::RIGHT;
				c.left = false;
				path.push(c);
				return Direction::LEFT;
			}
			if (c.down && !path.size() || c.down && path.top().backStep != Direction::DOWN && b.backStep != Direction::DOWN && b1.backStep != Direction::DOWN)
			{
				c.backStep = Direction::UP;
				c.down = false;
				path.push(c);
				return Direction::DOWN;
			}
			if (c.right && !path.size() || c.right && path.top().backStep != Direction::RIGHT && b.backStep != Direction::RIGHT)
			{
				c.backStep = Direction::LEFT;
				c.right = false;
				path.push(c);
				return Direction::RIGHT;
			}
		}
		else
		{
			if (flag1 == 1)
			{
				switch (b.backStep)
				{
				case Direction::LEFT:
					b.backStep = Direction::RIGHT;
					break;
				case Direction::RIGHT:
					b.backStep = Direction::LEFT;
					break;
				case Direction::UP:
					b.backStep = Direction::DOWN;
					break;
				case Direction::DOWN:
					b.backStep = Direction::UP;
					break;
				}
				int k = ch.top();
				ch.pop();
				ch.push(k + 1);
				flag1 += 1;

				if (c.up && !path.size() || c.up && path.top().backStep != Direction::UP && b.backStep != Direction::UP && b1.backStep != Direction::UP && st.top().backStep != Direction::UP)
				{
					c.backStep = Direction::DOWN;
					c.up = false; path.top().backStep = b.backStep;
					path.push(c);
					return Direction::UP;
				}
				if (c.left && !path.size() || c.left && path.top().backStep != Direction::LEFT && b.backStep != Direction::LEFT && b1.backStep != Direction::LEFT && st.top().backStep != Direction::LEFT)
				{
					c.backStep = Direction::RIGHT;
					c.left = false;
					path.top().backStep = b.backStep;
					path.push(c);
					return Direction::LEFT;
				}
				if (c.down && !path.size() || c.down && path.top().backStep != Direction::DOWN && b.backStep != Direction::DOWN && b1.backStep != Direction::DOWN && st.top().backStep != Direction::DOWN)
				{
					c.backStep = Direction::UP;
					c.down = false; path.top().backStep = b.backStep;
					path.push(c);
					return Direction::DOWN;
				}
				if (c.right && !path.size() || c.right && path.top().backStep != Direction::RIGHT && b.backStep != Direction::RIGHT && st.top().backStep != Direction::RIGHT)
				{
					c.backStep = Direction::LEFT;
					c.right = false;
					path.top().backStep = b.backStep;
					path.push(c);

					return Direction::RIGHT;
				}
			}
			else
			{
				if (flag1 == 2)
				{
					flag1 = 0;
					switch (b.backStep)
					{
					case Direction::LEFT:
						b.backStep = Direction::RIGHT;
						break;
					case Direction::RIGHT:
						b.backStep = Direction::LEFT;
						break;
					case Direction::UP:
						b.backStep = Direction::DOWN;
						break;
					case Direction::DOWN:
						b.backStep = Direction::UP;
						break;
					}

					if (c.up && !path.size() || c.up && path.top().backStep != Direction::UP && b.backStep != Direction::UP && b1.backStep != Direction::UP && st.top().backStep != Direction::UP && kost.backStep != Direction::UP)
					{
						c.backStep = Direction::DOWN;
						c.up = false;
						path.push(c);
						return Direction::UP;
					}
					if (c.left && !path.size() || c.left && path.top().backStep != Direction::LEFT && b.backStep != Direction::LEFT && b1.backStep != Direction::LEFT && st.top().backStep != Direction::LEFT && kost.backStep != Direction::LEFT)
					{
						c.backStep = Direction::RIGHT;
						c.left = false;
						path.push(c);
						return Direction::LEFT;
					}
					if (c.down && !path.size() || c.down && path.top().backStep != Direction::DOWN && b.backStep != Direction::DOWN && b1.backStep != Direction::DOWN && st.top().backStep != Direction::DOWN && kost.backStep != Direction::DOWN)
					{
						c.backStep = Direction::UP;
						c.down = false;
						path.push(c);
						return Direction::DOWN;
					}
					if (c.right && !path.size() || c.right && path.top().backStep != Direction::RIGHT && b.backStep != Direction::RIGHT && st.top().backStep != Direction::RIGHT && kost.backStep != Direction::RIGHT)
					{
						c.backStep = Direction::LEFT;
						c.right = false;
						path.push(c);
						return Direction::RIGHT;
					}
				}
			}
		}



	}
	else {
		if (!path.size() && c.kol == 4 && flag)
		{
			flag = false;

			switch (b.backStep)
			{
			case Direction::LEFT:
				b.backStep = Direction::RIGHT;
				break;
			case Direction::RIGHT:
				b.backStep = Direction::LEFT;
				break;
			case Direction::UP:
				b.backStep = Direction::DOWN;
				break;
			case Direction::DOWN:
				b.backStep = Direction::UP;
				break;
			}
			path.push(b);
			if (c.right && !path.size() || c.right && b.backStep != Direction::RIGHT)
			{
				c.backStep = Direction::LEFT;
				c.right = false;
				path.push(c);
				return Direction::RIGHT;
			}
			if (c.up && !path.size() || c.up && b.backStep != Direction::UP)
			{
				c.backStep = Direction::DOWN;
				c.up = false;
				path.push(c);
				return Direction::UP;
			}
			if (c.left && !path.size() || c.left && b.backStep != Direction::LEFT)
			{
				c.backStep = Direction::RIGHT;
				c.left = false;
				path.push(c);
				return Direction::LEFT;
			}
			if (c.down && !path.size() || c.down && b.backStep != Direction::DOWN)
			{
				c.backStep = Direction::UP;
				c.down = false;
				path.push(c);
				return Direction::DOWN;
			}


		}

	}

	if (!flag)
	{
		if (c.up && !path.size() || c.up && path.top().backStep != Direction::UP)
		{
			c.backStep = Direction::DOWN;
			c.up = false;
			path.push(c);
			return Direction::UP;
		}
		if (c.left && !path.size() || c.left && path.top().backStep != Direction::LEFT)
		{
			c.backStep = Direction::RIGHT;
			c.left = false;
			path.push(c);
			return Direction::LEFT;
		}
		if (c.down && !path.size() || c.down && path.top().backStep != Direction::DOWN)
		{
			c.backStep = Direction::UP;
			c.down = false;
			path.push(c);
			return Direction::DOWN;
		}

		if (c.right && !path.size() || c.right && path.top().backStep != Direction::RIGHT)
		{
			c.backStep = Direction::LEFT;
			c.right = false;
			path.push(c);
			return Direction::RIGHT;
		}
	}
	else
	{
		b = path.top();
		path.pop();
		return b.backStep;
	}
	flag = true;
	Cell q = path.top();
	b = q;
	path.pop();


	return q.backStep;

}

#endif //LABYRINTH_RUNNER_HPP
