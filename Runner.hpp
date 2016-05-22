//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include "RunnerBase.hpp"
#include <stack>



using namespace std;


static const int SAFE = 0;
static const int WALL = 3315;
static const int FROM = 999999;

class Cell
{
public:
	int left = SAFE;
	int right = SAFE;
	int up = SAFE;
	int down = SAFE;

    Cell();
	Cell(const Cell& c);
};



class Runner : public RunnerBase {
public:
	std::stack<Cell> path;
	int rebellion;
	bool flag;
    Direction step();
};

#endif //LABYRINTH_RUNNER_HPP
