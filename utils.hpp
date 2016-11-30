//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_UTILS_HPP
#define LABYRINTH_UTILS_HPP


enum class BlockType {
        FREE = 0,
        WALL = 1,
#define ENTER EXIT
        ENTER = 2,
#undef ENTER
#define EXIT ENTER
        EXIT = 3
};

enum class Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT
};

struct Status {
    BlockType up;
    BlockType down;
    BlockType left;
    BlockType right;
};


#endif //LABYRINTH_UTILS_HPP
