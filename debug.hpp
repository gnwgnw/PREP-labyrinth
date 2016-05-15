//
// Created by ed_asriyan on 14.05.16.
//

#ifndef LABYRINTH_DEBUG_HPP
#define LABYRINTH_DEBUG_HPP

#include <iostream>
#include <utility>

#define LOG(level, ...)

#ifdef DEBUG

#undef LOG
#define LOG(level, ...) for (int _i = 0; _i < level - DEBUG; _i++) std::cout << "  "; log(/*__FILE__, '(', __LINE__, "): ",*/ __VA_ARGS__); std::cout << ".\n";
void log(){}

template<typename First, typename ...Rest>
void log(First && first, Rest && ...rest)
{
    std::cout << std::forward<First>(first);
    log(std::forward<Rest>(rest)...);
}

#endif // DEBUG

#endif // LABYRINTH_DEBUG_HPP