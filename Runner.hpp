
//
// Created by tsv on 09.05.16.
//
#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP
#include <list>
#include <fstream>
#include "RunnerBase.hpp"

#define square 3000

using namespace std;

struct Node
{
    int _x;
    int _y;
    Node(int a, int b) : _x(a), _y(b) {}
    Node() : _x(0), _y(0) {}
};

class Runner: public RunnerBase {
    private:

        list<Node> road;
        int counter;
        int x;
        int y;
        int size;
        int demen;
        Node tmp;
        bool **arr;
        int old_x;
        int old_y;
        int num_directions;
        Direction next_step;
        void add_memory();
        bool if_exit();
        void find_directions();
        void find_directions_1();
        void find_directions_2();
        void find_directions_3();
        void find_directions_4();
        void find_directions_first();
        void find_directions_second();
        void arr_del();
    public:
        Runner();
        Direction step();
};


#endif //LABYRINTH_RUNNER_HPP
