//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP
#include <set>
#include <list>

#include "RunnerBase.hpp"

using namespace std;

class Runner: public RunnerBase {
    private:
        set<pair<int, int> > arr;
        list<pair<int, int> > road;
        int x;
        int y;
        int old_x;
        int old_y;
        int num_directions;
        Direction next_step;
        bool was_went(const int a, const int b);
        void find_directions();
    public:
        Direction step();
        Runner() :  x(0), y(0) {}
};


#endif //LABYRINTH_RUNNER_HPP
