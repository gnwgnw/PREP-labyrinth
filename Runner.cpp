//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"

void Cell::setTrue()
{
	left = true;
	right = true;
	up = true;
	down = true;
}

void Cell::setStatus(Status& st)
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

Cell::Cell()
{
	left = false;
	right = false;
	up = false;
	down = false;
}

Cell::Cell(const Cell&c)
{
	left = c.left;
	right = c.right;
	up = c.up;
	down = c.down;
	backStep = c.backStep;
}

Cell::Cell(int i)
{
	left = true;
	right = true;
	up = true;
	down = true;
}

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

		if (c.left && !path.size() || c.left && path.top().backStep != Direction::LEFT && b.backStep != Direction::LEFT)
				{
					c.backStep = Direction::RIGHT;
					c.left = false;
					path.push(c);
					return Direction::LEFT;
				}
		if (c.up && !path.size() || c.up && path.top().backStep != Direction::UP && b.backStep != Direction::UP)
		{
			c.backStep = Direction::DOWN;
			c.up = false;
			path.push(c);
			return Direction::UP;
		}
		if (c.right && !path.size() || c.right && path.top().backStep != Direction::RIGHT && b.backStep != Direction::RIGHT)
		{
			c.backStep = Direction::LEFT;
			c.right = false;
			path.push(c);
			return Direction::RIGHT;
		}
		if (c.down && !path.size() || c.down && path.top().backStep != Direction::DOWN && b.backStep != Direction::DOWN)
		{
			c.backStep = Direction::UP;
			c.down = false;
			path.push(c);
			return Direction::DOWN;
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
			if (c.left && !path.size() || c.left && b.backStep != Direction::LEFT)
						{
							c.backStep = Direction::RIGHT;
							c.left = false;
							path.push(c);
							return Direction::LEFT;
						}
			if (c.up && !path.size() || c.up && b.backStep != Direction::UP)
			{
				c.backStep = Direction::DOWN;
				c.up = false;
				path.push(c);
				return Direction::UP;
			}
			if (c.right && !path.size() || c.right && b.backStep != Direction::RIGHT)
			{
				c.backStep = Direction::LEFT;
				c.right = false;
				path.push(c);
				return Direction::RIGHT;
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
			if (c.left && !path.size() || c.left && path.top().backStep != Direction::LEFT && b.backStep != Direction::LEFT && b1.backStep != Direction::LEFT)
						{
							c.backStep = Direction::RIGHT;
							c.left = false;
							path.push(c);
							return Direction::LEFT;
						}
			if (c.up && !path.size() || c.up && path.top().backStep != Direction::UP && b.backStep != Direction::UP && b1.backStep != Direction::UP)
			{
				c.backStep = Direction::DOWN;
				c.up = false;
				path.push(c);
				return Direction::UP;
			}
			if (c.right && !path.size() || c.right && path.top().backStep != Direction::RIGHT && b.backStep != Direction::RIGHT)
			{
				c.backStep = Direction::LEFT;
				c.right = false;
				path.push(c);
				return Direction::RIGHT;
			}
			if (c.down && !path.size() || c.down && path.top().backStep != Direction::DOWN && b.backStep != Direction::DOWN && b1.backStep != Direction::DOWN)
			{
				c.backStep = Direction::UP;
				c.down = false;
				path.push(c);
				return Direction::DOWN;
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
				if (c.left && !path.size() || c.left && path.top().backStep != Direction::LEFT && b.backStep != Direction::LEFT && b1.backStep != Direction::LEFT && st.top().backStep != Direction::LEFT)
								{
									c.backStep = Direction::RIGHT;
									c.left = false;
									path.top().backStep = b.backStep;
									path.push(c);
									return Direction::LEFT;
								}
				if (c.up && !path.size() || c.up && path.top().backStep != Direction::UP && b.backStep != Direction::UP && b1.backStep != Direction::UP && st.top().backStep != Direction::UP)
				{
					c.backStep = Direction::DOWN;
					c.up = false; path.top().backStep = b.backStep;
					path.push(c);
					return Direction::UP;
				}
				if (c.right && !path.size() || c.right && path.top().backStep != Direction::RIGHT && b.backStep != Direction::RIGHT && st.top().backStep != Direction::RIGHT)
				{
					c.backStep = Direction::LEFT;
					c.right = false;
					path.top().backStep = b.backStep;
					path.push(c);

					return Direction::RIGHT;
				}
				if (c.down && !path.size() || c.down && path.top().backStep != Direction::DOWN && b.backStep != Direction::DOWN && b1.backStep != Direction::DOWN && st.top().backStep != Direction::DOWN)
				{
					c.backStep = Direction::UP;
					c.down = false; path.top().backStep = b.backStep;
					path.push(c);
					return Direction::DOWN;
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
					if (c.left && !path.size() || c.left && path.top().backStep != Direction::LEFT && b.backStep != Direction::LEFT && b1.backStep != Direction::LEFT && st.top().backStep != Direction::LEFT && kost.backStep != Direction::LEFT)
										{
											c.backStep = Direction::RIGHT;
											c.left = false;
											path.push(c);
											return Direction::LEFT;
										}
					if (c.up && !path.size() || c.up && path.top().backStep != Direction::UP && b.backStep != Direction::UP && b1.backStep != Direction::UP && st.top().backStep != Direction::UP && kost.backStep != Direction::UP)
					{
						c.backStep = Direction::DOWN;
						c.up = false;
						path.push(c);
						return Direction::UP;
					}
					if (c.right && !path.size() || c.right && path.top().backStep != Direction::RIGHT && b.backStep != Direction::RIGHT && st.top().backStep != Direction::RIGHT && kost.backStep != Direction::RIGHT)
					{
						c.backStep = Direction::LEFT;
						c.right = false;
						path.push(c);
						return Direction::RIGHT;
					}
					if (c.down && !path.size() || c.down && path.top().backStep != Direction::DOWN && b.backStep != Direction::DOWN && b1.backStep != Direction::DOWN && st.top().backStep != Direction::DOWN && kost.backStep != Direction::DOWN)
					{
						c.backStep = Direction::UP;
						c.down = false;
						path.push(c);
						return Direction::DOWN;
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
			if (c.left && !path.size() || c.left && b.backStep != Direction::LEFT)
			{
				c.backStep = Direction::RIGHT;
				c.left = false;
				path.push(c);
				return Direction::LEFT;
			}
			if (c.up && !path.size() || c.up && b.backStep != Direction::UP)
			{
				c.backStep = Direction::DOWN;
				c.up = false;
				path.push(c);
				return Direction::UP;
			}
			if (c.right && !path.size() || c.right && b.backStep != Direction::RIGHT)
			{
				c.backStep = Direction::LEFT;
				c.right = false;
				path.push(c);
				return Direction::RIGHT;
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
		if (c.left && !path.size() || c.left && path.top().backStep != Direction::LEFT)
		{
			c.backStep = Direction::RIGHT;
			c.left = false;
			path.push(c);
			return Direction::LEFT;
		}
		if (c.up && !path.size() || c.up && path.top().backStep != Direction::UP)
		{
			c.backStep = Direction::DOWN;
			c.up = false;
			path.push(c);
			return Direction::UP;
		}
		if (c.right && !path.size() || c.right && path.top().backStep != Direction::RIGHT)
		{
			c.backStep = Direction::LEFT;
			c.right = false;
			path.push(c);
			return Direction::RIGHT;
		}
		if (c.down && !path.size() || c.down && path.top().backStep != Direction::DOWN)
		{
			c.backStep = Direction::UP;
			c.down = false;
			path.push(c);
			return Direction::DOWN;
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