//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"

bool operator != (const Status &s1, const Status &s2) {
    return (s1.up    != s2.up   ||
            s1.down  != s2.down ||
            s1.left  != s2.left ||
            s1.right != s2.right);
}

static Direction invert(const Direction d) {
    if (d == Direction::UP)
        return Direction::DOWN;
    else if (d == Direction::DOWN)
        return Direction::UP;
    else if (d == Direction::LEFT)
        return Direction::RIGHT;
    else
        return Direction::LEFT;
}

Direction Runner::step()
{
    Direction d;

    if (_history.size() == 0)
        _history.push(Direction::NONE);

    if (goAhead) {
        Fork f;

        f.base = _history.top();

        if (current_status.up == BlockType::WALL    || f.base == Direction::UP)
            f.wasUp = true;
        else
            f.wasUp = false;
        if (current_status.down  == BlockType::WALL || f.base == Direction::DOWN)
            f.wasDown = true;
        else
            f.wasDown  = false;
        if (current_status.left  == BlockType::WALL || f.base == Direction::LEFT)
            f.wasLeft = true;
        else
            f.wasLeft  = false;
        if (current_status.right == BlockType::WALL || f.base == Direction::RIGHT)
            f.wasRight = true;
        else
            f.wasRight = false;

        _fork.push(f);
    }
    else
        _fork.pop(); //?

    if (__countWalls() == 3 && _fork.top().base != Direction::NONE)
        goAhead = false;
    if (__countWalls() < 2)
        goAhead = true;

    if (_fork.top().wasUp   == true && _fork.top().wasDown  == true &&
        _fork.top().wasLeft == true && _fork.top().wasRight == true) {
        _history.top() = invert(_fork.top().base);
        goAhead = false;
        _history.top() = invert(_fork.top().base);
        return _fork.top().base;
    }
    else if ((d = __freeFork()) != Direction::NONE) {
        goAhead = true;
        switch (d) {
        case Direction::UP :
            _fork.top().wasUp = true;
            break;
        case Direction::DOWN :
            _fork.top().wasDown = true;
            break;
        case Direction::LEFT :
            _fork.top().wasLeft = true;
            break;
        case Direction::RIGHT :
            _fork.top().wasRight = true;
            break;
        default:
            break;
        }

        _history.top() = invert(d);
        return d;
    }
    else if (current_status.right != BlockType::WALL && _fork.top().wasRight == false) {
        goAhead = true;
        _fork.top().wasRight = true;

        _history.top() = Direction::LEFT;
        return Direction::RIGHT;
    }
    else if (current_status.up == BlockType::WALL && _fork.top().wasDown == false) {
        goAhead = true;
        _fork.top().wasDown = true;

        _history.top() = Direction::UP;
        return Direction::DOWN;
    }
    else if (current_status.up == BlockType::WALL && _fork.top().wasLeft == false) {
        goAhead = true;
        _fork.top().wasLeft = true;

        _history.top() = Direction::RIGHT;
        return Direction::LEFT;
    }
    else if (current_status.down == BlockType::WALL && _fork.top().wasUp == false) {
        goAhead = true;
        _fork.top().wasUp = true;

        _history.top() = Direction::DOWN;
        return Direction::UP;
    }
    else if (current_status.down == BlockType::WALL && _fork.top().wasLeft == false) {
        goAhead = true;
        _fork.top().wasLeft = true;

        _history.top() = Direction::RIGHT;
        return Direction::LEFT;
    }
    else if (__countWalls() == 1) {
        if (_history.top() == Direction::LEFT && _fork.top().wasDown == false) {
            goAhead = true;
            _history.top() = Direction::UP;

            _fork.top().wasDown = true;
            return Direction::DOWN;
        }
        else if (_history.top() == Direction::LEFT && _fork.top().wasUp == false) {
            goAhead = true;
            _history.top() = Direction::DOWN;

            _fork.top().wasUp = true;
            return Direction::UP;
        }
        else if (_history.top() == Direction::UP && _fork.top().wasDown == false) {
            goAhead = true;
            _history.top() = Direction::UP;

            _fork.top().wasDown = true;
            return Direction::DOWN;
        }
        else if (_history.top() == Direction::DOWN && _fork.top().wasUp == false) {
            goAhead = true;
            _history.top() = Direction::DOWN;

            _fork.top().wasUp = true;
            return Direction::UP;
        }
        else if (_history.top() == Direction::UP && _fork.top().wasLeft == false) {
            goAhead = true;
            _history.top() = Direction::RIGHT;

            _fork.top().wasLeft = true;
            return Direction::LEFT;
        }
        else if (_history.top() == Direction::DOWN && _fork.top().wasLeft == false) {
            goAhead = true;
            _history.top() = Direction::RIGHT;

            _fork.top().wasLeft = true;
            return Direction::LEFT;
        }
        else {
            goAhead = false;

            d = _history.top();
            _history.top() = invert(_history.top());
            switch (d) {
            case Direction::UP :
                _fork.top().wasUp = true;
                break;
            case Direction::DOWN :
                _fork.top().wasDown = true;
                break;
            case Direction::LEFT :
                _fork.top().wasLeft = true;
                break;
            case Direction::RIGHT :
                _fork.top().wasRight = true;
                break;
            default:
                break;
            }
            return d;
        }
    }
    else if (!goAhead) {
        _history.top() = invert(_fork.top().base);
        return _fork.top().base;
    }
}

size_t Runner::__countWalls() const
{
    size_t nWalls = 0;
    if (current_status.up    == BlockType::WALL)
        nWalls++;
    if (current_status.down  == BlockType::WALL)
        nWalls++;
    if (current_status.left  == BlockType::WALL)
        nWalls++;
    if (current_status.right == BlockType::WALL)
        nWalls++;

    return nWalls;
}

Direction Runner::__freeFork() const
{
    Fork f = _fork.top();

    if (f.wasDown == true && f.wasLeft == true && f.wasRight == true && f.wasUp == false)
        return Direction::UP;
    else if (f.wasDown == true && f.wasRight == true && f.wasUp == true && f.wasLeft == false)
        return Direction::LEFT;
    else if (f.wasDown == true && f.wasLeft == true && f.wasUp == true && f.wasRight == false)
        return Direction::RIGHT;
    else if (f.wasUp == true && f.wasLeft == true && f.wasRight == true && f.wasDown == false)
        return Direction::DOWN;
    else
        return Direction::NONE;
}
