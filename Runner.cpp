#include "Runner.hpp"
#include <iostream>

#include <stdlib.h> 
#include <time.h>
#include <assert.h>
#include <stack>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

const unsigned int COUNT_VECTORS = 4;

class info
{
public:
	info(Status status, int exit_)
	{
		this->exit = exit_;
		free_vectors(status);
	}

	int* next_vector()
	{
		this->cursor += 1;
		if(cursor >= 4 || v[cursor] == -1)

			return nullptr;

		return &(v[cursor]);
	}

	int get_exit()
	{
		return exit;
	}

private:
	int* v;
	int cursor;
	int exit;

	void free_vectors(Status status)
	{
		int* tmp = new int[COUNT_VECTORS];	
		
		int position = 0;
		this->cursor = -1;

		if((int) status.right == 0)
			if(RIGHT != exit)
				tmp[position++] = RIGHT;

		if((int) status.up == 0)
			if(UP != exit)
				tmp[position++] = UP;

		if((int) status.down == 0)
			if(DOWN != exit)
				tmp[position++] = DOWN;

		if((int) status.left == 0)
			if(LEFT != exit)
				tmp[position++] = LEFT;

		// for(int i = 0; i <= position - 1; i++)
		// {
		// 	std::cout << " / " << tmp[i];
		// }


		for(int i = position; i < COUNT_VECTORS; i++)
		{
			tmp[i] = -1;
		}


		v = tmp;
	}

};

int reverse(int d)
{
	if(d <= 1)

		return ++d % 2;

	else

		return (++d % 2) + 2;
}

void print(Status st)
{
	std::cout << " UP " << (int) st.up;
	std::cout << " DOWN " << (int) st.down;
	std::cout << " LEFT " << (int) st.left;
	std::cout << " RIGHT " << (int) st.right;
	std::cout << std::endl;
}

class path
{
public:
	bool return_mode = false;

	std::stack<info*> stack_info;

	int now_vector = -1;
	info* now_info = nullptr;

	path() {}

	void new_branch(Status status)
	{
		//std::cout << std::endl << "NEW BRANCH FROM " << reverse(now_vector) << std::endl;
		now_info = new info(status, reverse(now_vector));
		stack_info.push(now_info);

		now_vector = -1;
	}

	int forward(int* status)
	{
		if(now_vector == -1)
		{
			int* tmp = now_info->next_vector();
			if(tmp == nullptr)
			{
				now_vector = now_info->get_exit();
				
				// ERROR
				//assert(false);
				if(now_vector == -1)
					return -1;

				stack_info.pop();
				delete now_info;

				now_info = stack_info.top();
			}
			else
			{
				return_mode = false;
				now_vector = *tmp;
			}
			
		}

		if(status[now_vector] == 0)
		
			return now_vector;

		for(int i = 0; i < 4; i++)
		{
			if(i != reverse(now_vector) && status[i] == 0)
			{
				now_vector = i;
				break;
			}
		}
		return now_vector;
	}
};

path p;
int* paths = new int[4];
int result;

int get_free_sum()
{
	int sum = 0;
	for(int i = 0; i < COUNT_VECTORS;  i++)
		if(paths[i] == 0)
			sum++;

	return sum;
}

Direction Runner::step()
{
	// c++;
	// if(c > 30)
	// 	return ((Direction) 0);

	if(p.now_vector == -1)
		
		p.new_branch(current_status);

	paths[UP] = (int) current_status.up;
	paths[DOWN] = (int) current_status.down;
	paths[LEFT] = (int) current_status.left;
	paths[RIGHT] = (int) current_status.right;
	for(int i = 0; i < COUNT_VECTORS; i++)
		if(paths[i] == 2)
			paths[i] = 0;
		else if(paths[i] == 3)
			return (Direction) i;

	int free = get_free_sum();

	if(free > 2)
	{
		if(!p.return_mode)
		{
			p.new_branch(current_status);
		}
		else
		{
			p.now_vector = -1;
		}
	}

	if(free == 1 && p.now_vector != -1)
	{
		p.now_vector = reverse(p.now_vector);
		p.return_mode = true;
	}

	
	result = p.forward(paths);
	
	return (Direction) result;
}