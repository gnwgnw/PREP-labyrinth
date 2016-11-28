//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_FIELD_HPP
#define LABYRINTH_FIELD_HPP

#include <vector>
#include <istream>
#include <chrono>

#include "Runner.hpp"
#include "utils.hpp"


using std::vector;

class Field {
    private:
        struct Position {
            size_t x;
            size_t y;
        };

        size_t tic_count = 0;
        bool done = false;

        vector<vector<BlockType>> field;
        Runner runner;
        std::chrono::steady_clock::time_point start_time;

        Position current_position;

        void set_runner_current_status();
        std::chrono::microseconds get_time_elapsed_mcs() const;

    public:

        friend std::istream& operator>>(std::istream& is, Field& field);

        bool tic();
        bool is_done();

        void result(std::ostream& os);
        void start();
};

std::istream& operator>>(std::istream& is, Field& field);
std::istream& operator>>(std::istream& is, BlockType& block_type);


#endif //LABYRINTH_FIELD_HPP
