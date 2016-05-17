//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"
#include <iostream>

Direction Runner::step()
{
    Direction PRV = prevStep;
    Direction nextStep = Direction::RIGHT;
    Status sts = current_status;
    if (sizeFork() <= 2)
    {
        nextStep = justGo();
        prevStep = inverse(nextStep);
        return nextStep;
    }
    if (!deadlock)
    {
        forkMem.push(prevStep);

        while (!canGo(goRight(prevStep)))
            prevStep = goRight(prevStep);

        nextStep = goRight(prevStep);
        prevStep = inverse(nextStep);
        return nextStep;
    }
    if (deadlock)
    {

        while (!canGo(goRight(prevStep)) && goRight(prevStep) != forkMem.top())
            prevStep = goRight(prevStep);

        if (goRight(prevStep) == forkMem.top())
        {
            deadlock = true;
            nextStep = forkMem.top();
            forkMem.pop();
            return nextStep;
        }
        deadlock = false;
        nextStep = goRight(prevStep);
        prevStep = inverse(nextStep);
        return nextStep;

    }
//   if (goRight(prevStep) == forkMem.top())
//    {
//        deadlock = true;
//        nextStep = forkMem.top();
//        forkMem.pop();
//        return nextStep;
//    }

}
bool Runner::canGo(Direction d)
{
    if (d == Direction::DOWN && current_status.down != BlockType::WALL)
        return true;
    if (d == Direction::UP && current_status.up != BlockType::WALL)
        return true;
    if ( d == Direction::LEFT && current_status.left != BlockType::WALL)
        return true;
    if ( d == Direction::RIGHT && current_status.right != BlockType::WALL)
        return true;

    return false;
}
Direction Runner::goRight(Direction d)
{
    if (d == Direction::DOWN)
        return Direction::RIGHT;
    if (d == Direction::UP)
        return Direction::LEFT;
    if (d == Direction::LEFT)
        return Direction::DOWN;
    if (d == Direction::RIGHT)
        return Direction::UP;
}
Direction Runner::goLeft(Direction d)
{
    if (d == Direction::DOWN)
        return Direction::LEFT;
    if (d == Direction::UP)
        return Direction::RIGHT;
    if (d == Direction::LEFT)
        return Direction::UP;
    if (d == Direction::RIGHT)
        return Direction::DOWN;
}
Direction Runner::inverse(Direction d)
{
    if (d == Direction::DOWN)
        return Direction::UP;
    if (d == Direction::UP)
        return Direction::DOWN;
    if (d == Direction::LEFT)
        return Direction::RIGHT;
    if (d == Direction::RIGHT)
        return Direction::LEFT;
}
int Runner::sizeFork()
{
    int wayNumber = 0;
    if (current_status.down != BlockType::WALL)
        wayNumber++;
    if (current_status.up != BlockType::WALL)
        wayNumber++;
    if (current_status.left != BlockType::WALL)
        wayNumber++;
    if (current_status.right != BlockType::WALL)
        wayNumber++;

    return  wayNumber;
}
Direction Runner::justGo()
{
    if (prevStep != Direction::DOWN && current_status.down != BlockType::WALL)
        return Direction::DOWN;
    if (prevStep != Direction::UP && current_status.up != BlockType::WALL)
        return Direction::UP;
    if ( prevStep != Direction::LEFT && current_status.left != BlockType::WALL)
        return Direction::LEFT;
    if ( prevStep != Direction::RIGHT && current_status.right != BlockType::WALL)
        return Direction::RIGHT;

    deadlock = true;
    return prevStep;
}
