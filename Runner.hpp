//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include "RunnerBase.hpp"
#include <stack>

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

	Cell();

	Cell(int i);

	Cell(const Cell&c);

	~Cell() {};

	void setStatus(Status& st);

	void setTrue();

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

#endif //LABYRINTH_RUNNER_HPP
