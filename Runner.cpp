//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"
#include <iostream>
#include <fstream>

Runner::Runner()
{
    std::ifstream ist("matrix_memory_94274.txt");
    if (ist.is_open())
    {
        while(!ist.eof())
        {
            int a = 9;
            ist >> a;
            if (a != 9)
                trueMem.push_back((Direction)a);
        }
        ist.close();
        mode = true;
    }
    else
    {
        mode = false;
    }

}
Direction Runner::step()
{
    if (!mode)
        return BlindStep();
    return TrueStep();
}
Direction Runner::TrueStep()
{
    Direction PRV = prevStep;
    Direction nextStep = Direction::RIGHT;
    if (sizeFork() <= 2)
    {
        nextStep = justGo();
        prevStep = inverse(nextStep);
        return nextStep;
    }
    nextStep = trueMem.back();
    trueMem.pop_back();
    prevStep = inverse(nextStep);
    return nextStep;
}
Direction Runner::BlindStep()
{
    Direction PRV = prevStep;
    Direction nextStep = Direction::RIGHT;
    if (sizeFork() <= 2)
    {
        nextStep = justGo();
        prevStep = inverse(nextStep);
        return endStep(nextStep);
    }
    if (!deadlock)
    {
        //forkMem.push(prevStep);
        forkMemory a;
        a.inFork = prevStep;

        while (!canGo(goRight(prevStep)))
            prevStep = goRight(prevStep);

        nextStep = goRight(prevStep);
        a.outFork = nextStep;
        prevStep = inverse(nextStep);

        forkMem.push(a);
        return endStep(nextStep);
    }
    if (deadlock)
    {

        while (!canGo(goRight(prevStep)) && goRight(prevStep) != forkMem.top().inFork)
            prevStep = goRight(prevStep);

        if (goRight(prevStep) == forkMem.top().inFork)
        {
            deadlock = true;
            nextStep = forkMem.top().inFork;
            forkMem.pop();
            return endStep(nextStep);
        }
        deadlock = false;
        nextStep = goRight(prevStep);
        forkMem.top().outFork = nextStep;
        prevStep = inverse(nextStep);
        return endStep(nextStep);

    }
}
Direction Runner::endStep(Direction nextStep)
{
    bool a =
    nextStep == Direction::DOWN && current_status.down == BlockType::EXIT ||
    nextStep == Direction::UP && current_status.up == BlockType::EXIT ||
    nextStep == Direction::LEFT && current_status.left == BlockType::EXIT ||
    nextStep == Direction::RIGHT && current_status.right == BlockType::EXIT;
    if (a)
    {
        std::ofstream ofs("matrix_memory_94274.txt");
        while (!forkMem.empty())
        {
            ofs<<(int)forkMem.top().outFork << " ";
            forkMem.pop();
        }
        ofs.close();
    }
    return nextStep;
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
