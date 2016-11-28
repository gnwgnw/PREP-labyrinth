//
// Created by tsv on 09.05.16.
//

#include "Field.hpp"
#include <iostream>


std::istream& operator>>(std::istream& is, Field& field)
{
    size_t rows = 0;
    size_t cols = 0;

    is >> rows >> cols;

    field.field.resize(rows);
    for (auto& row: field.field) {
        row.resize(cols);
    }

    BlockType block_type;

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            is >> block_type;
            field.field[i][j] = block_type;

            if (block_type == BlockType::ENTER) {
                field.current_position = {i, j};
            }
        }
    }

    field.set_runner_current_status();

    return is;
}

std::istream& operator>>(std::istream& is, BlockType& block_type)
{
    int val = 0;
    is >> val;
    block_type = static_cast<BlockType>(val);

    return is;
}

bool Field::tic()
{
    const auto MAX_EXECUTION_TIME_SEC = 60;
    const auto elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>(get_time_elapsed_mcs()).count();
    if (elapsed_seconds > MAX_EXECUTION_TIME_SEC) {
        std::cerr << "solution got too much time: " << elapsed_seconds << " sec" << std::endl;
        return false;
    }

    ++tic_count;

    Direction direction = runner.step();

    auto i = current_position.x;
    auto j = current_position.y;

    switch (direction) {
        case Direction::UP: {
            --i;
            break;
        }
        case Direction::DOWN: {
            ++i;
            break;
        }
        case Direction::LEFT: {
            --j;
            break;
        }
        case Direction::RIGHT: {
            ++j;
            break;
        }
    }

    auto next_block_type = field[i][j];

    if (next_block_type != BlockType::WALL) {
        current_position = {i, j};
        set_runner_current_status();

        if (next_block_type == BlockType::EXIT) {
            done = true;
        }
    }

    return true;
}

void Field::set_runner_current_status()
{
    auto i = current_position.x;
    auto j = current_position.y;

    Status status;
    status.up = field[i - 1][j];
    status.down = field[i + 1][j];
    status.left = field[i][j - 1];
    status.right = field[i][j + 1];

    runner.set_current_status(status);
}

bool Field::is_done()
{
    return done;
}

void Field::result(std::ostream& os)
{
    const auto elapsed_time_mcs = get_time_elapsed_mcs().count();
    os << "Total steps: " << tic_count << ", time: " << elapsed_time_mcs << " mcs" << std::endl;
}

void Field::start()
{
    start_time = std::chrono::steady_clock::now();
}

std::chrono::microseconds Field::get_time_elapsed_mcs() const
{
    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start_time);
}
