//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"

//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"

typedef BlockType B;
typedef Direction D;

bool Runner::include(D d) {
    int x = history.back().x;
    int y = history.back().y;

    switch (d) {
        case Direction::RIGHT: {
            x++; // следующий coord
            break;
        }

        case Direction::LEFT: {
            x--;
            break;
        }

        case Direction::UP: {
            y++;
            break;
        }

        case Direction::DOWN: {
            y--;
            break;
        }

    }

    for (int i = history.size() - 1; i >=0 ; --i) {
        if (history[i].x == x && history[i].y == y) return true;
    }
    return false;
}


bool Runner::is_free(D d) {

    switch (d) {
        case D::RIGHT: {
            if ((current_status.right == B::FREE || current_status.right == B::EXIT)
                && !history.back().right &&
                !include(D::RIGHT)) {
                return true;
            }
            break;
        }


        case D::UP: {
            if ((current_status.up == B::FREE || current_status.up == B::EXIT) &&
                !history.back().up &&
                !include(D::UP)) {
                return true;
            }
            break;
        }

        case D::LEFT: {
            if ((current_status.left == B::FREE || current_status.left == B::EXIT) &&
                !history.back().left &&
                !include(D::LEFT)) {
                return true;
            }
            break;
        }

        case D::DOWN: {
            if ((current_status.down == B::FREE || current_status.down == B::EXIT) &&
                !history.back().down &&
                !include(D::DOWN)) {
                return true;
            }
            break;

        }
    }

    return false;

}

bool Runner::deadlock()
{
    int flag = 0;

    if (is_free(D::RIGHT)) {
        flag ++;
    }

    if (is_free(D::LEFT)) {
        flag++;
    }

    if (is_free(D::UP)) {
        flag++;
    }

    if (is_free(D::DOWN)) {
        flag++;
    }

    if (flag == 0) return true;

    return false;
}

D reverse(D d) {
    if (d == D::DOWN) return D::UP;
    if (d == D::RIGHT) return D::LEFT;
    if (d == D::LEFT) return D::RIGHT;
    if (d == D::UP) return D::DOWN;
}


std::vector<Direction >* Runner::where() {

    std::vector<Direction> *v = new std::vector<Direction >();

    if (is_free(D::DOWN)) {
        v->push_back(D::DOWN);
    }

    if (is_free(D::RIGHT)) {
        v->push_back(D::RIGHT);
    }

    if (is_free(D::UP)) {
        v->push_back(D::UP);
    }

    if (is_free(D::LEFT)) {
        v->push_back(D::LEFT);
    }
    return v;
}




Direction Runner::step(){

    if (history.empty()) {
        Coord coord;

        coord.x = 0;
        coord.y = 0;

        history.push_back(coord);
    }

    if (deadlock()) {
        history.erase(history.end()-1);
        return reverse(history.back().direction); // Если тупик вернуться назад
    }
    else {
        std::vector<Direction> *v = where();

        int n = v->size();
        int rand_direction = rand() % n;

        D dir = v->data()[rand_direction];

        delete (v);


        switch (dir) {
            case D::RIGHT: {
                history.back().right = true;
                history.back().direction = D::RIGHT;

                Coord coord;
                coord.x = history.back().x + 1;
                coord.y = history.back().y;
                coord.left = true;

                history.push_back(coord);

                return D::RIGHT;
            }

            case D::LEFT: {
                history.back().left = true;
                history.back().direction = D::LEFT;

                Coord coord;
                coord.x = history.back().x - 1;
                coord.y = history.back().y;
                coord.right = true;

                history.push_back(coord);
                return D::LEFT;
            }
            case D::UP: {
                history.back().up = true;
                history.back().direction = D::UP;

                Coord coord;
                coord.x = history.back().x;
                coord.y = history.back().y + 1;
                coord.down = true;

                history.push_back(coord);
                return D::UP;
            }
            case D::DOWN: {
                history.back().down = true;
                history.back().direction = D::DOWN;

                Coord coord;
                coord.x = history.back().x;
                coord.y = history.back().y - 1;
                coord.up = true;

                history.push_back(coord);
                return D::DOWN;
            }

        }


    }

}