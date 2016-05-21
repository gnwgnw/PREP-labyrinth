//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"
#include "iostream"

Direction Runner::step()
{
    if(current_status.down == BlockType::EXIT)
        return Direction::DOWN;

    else if (current_status.up == BlockType::EXIT)
        return Direction::UP;

    else if (current_status.right == BlockType::EXIT)
        return Direction::RIGHT;

    else if (current_status.left == BlockType::EXIT)
        return Direction::LEFT;


    if(map == nullptr)
    {
        map = new Point*[mapSize];
        for(int i = 0; i < mapSize; ++i)
            map[i] = new Point[mapSize];
        map[0][0].wave = 1;
        map[0][0].x = 0;
        map[0][0].y = 0;
    }

    if(position.x == maximalCoordinate || position.x == minimalCoordinate ||
       position.y == maximalCoordinate || position.y == minimalCoordinate)
    {
        int newSize = mapSize * 3;
        int newMinimalCoordinate = minimalCoordinate - mapSize;
        int newMaximalCoordinate = maximalCoordinate + mapSize;
        Point **newMap = new Point*[newSize];

        for(int i = 0; i < newSize; ++i)
        {
            newMap[i] = new Point[newSize];
            for(int j = 0; j < newSize; ++j)
            newMap[i][j] = {j + newMinimalCoordinate, i + newMinimalCoordinate, 0};
        }

        for(int i = 0; i < mapSize; ++i)
        {
            for(int j = 0; j < mapSize; ++j)
            {
                newMap[i + mapSize][j + mapSize] = map[i][j];
            }
        }

        for(int i = 0; i < mapSize; ++i)
            delete[] map[i];
        delete[] map;

        map = newMap;
        minimalCoordinate = newMinimalCoordinate;
        maximalCoordinate = newMaximalCoordinate;
        mapSize = newSize;

    }

    int xIndexForMap = position.x - minimalCoordinate;
    int yIndexForMap = position.y - minimalCoordinate;
    int currentWave = position.wave;

    if(current_status.up != BlockType::WALL && map[yIndexForMap + 1][xIndexForMap].wave == 0)
    {
        map[yIndexForMap + 1][xIndexForMap].wave = currentWave + 1;
    }

    if(current_status.down != BlockType::WALL && map[yIndexForMap - 1][xIndexForMap].wave == 0)
    {
        map[yIndexForMap - 1][xIndexForMap].wave = currentWave + 1;
    }

    if(current_status.left != BlockType::WALL && map[yIndexForMap][xIndexForMap - 1].wave == 0)
    {
        map[yIndexForMap][xIndexForMap - 1].wave = currentWave + 1;
    }

    if(current_status.right != BlockType::WALL && map[yIndexForMap][xIndexForMap + 1].wave == 0)
    {
        map[yIndexForMap][xIndexForMap + 1].wave = currentWave + 1;
    }

    map[yIndexForMap][xIndexForMap] = position;

    Point upper = map[yIndexForMap + 1][xIndexForMap];
    Point lower = map[yIndexForMap - 1][xIndexForMap];
    Point right = map[yIndexForMap][xIndexForMap + 1];
    Point left = map[yIndexForMap][xIndexForMap - 1];

    if((current_status.right != BlockType::WALL) && (right.wave - 1 == position.wave))
    {
        position = right;
        return Direction::RIGHT;
    }

    if((current_status.down != BlockType::WALL) && (lower.wave - 1 == position.wave))
    {
        position = lower;
        return Direction::DOWN;
    }

    if((current_status.left != BlockType::WALL) && (left.wave - 1 == position.wave))
    {
        position = left;
        return Direction::LEFT;
    }

    if((current_status.up != BlockType::WALL) && (upper.wave - 1 == position.wave))
    {
        position = upper;
        return Direction::UP;
    }

    if(current_status.right != BlockType::WALL && right.wave == position.wave - 1)
    {
        Point newPosition;
        newPosition.wave = -1;
        newPosition.x = xIndexForMap + minimalCoordinate;
        newPosition.y = yIndexForMap + minimalCoordinate;
        map[yIndexForMap][xIndexForMap] = newPosition;

        position = right;
        return Direction::RIGHT;
    }

    if(current_status.down != BlockType::WALL && lower.wave == position.wave - 1)
    {
        Point newPosition;
        newPosition.wave = -1;
        newPosition.x = xIndexForMap + minimalCoordinate;
        newPosition.y = yIndexForMap + minimalCoordinate;
        map[yIndexForMap][xIndexForMap] = newPosition;

        position = lower;
        return Direction::DOWN;
    }

    if(current_status.left != BlockType::WALL && left.wave == position.wave - 1)
    {
        Point newPosition;
        newPosition.wave = -1;
        newPosition.x = xIndexForMap + minimalCoordinate;
        newPosition.y = yIndexForMap + minimalCoordinate;
        map[yIndexForMap][xIndexForMap] = newPosition;

        position = left;
        return Direction::LEFT;
    }

    if(current_status.up != BlockType::WALL && upper.wave == position.wave - 1)
    {
        Point newPosition;
        newPosition.wave = -1;
        newPosition.x = xIndexForMap + minimalCoordinate;
        newPosition.y = yIndexForMap + minimalCoordinate;
        map[yIndexForMap][xIndexForMap] = newPosition;

        position = upper;
        return Direction::UP;
    }
}
