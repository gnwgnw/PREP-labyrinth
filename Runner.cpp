//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"
#include <vector>
#include <cstdlib>
#include "utils.hpp"

Direction Runner::step()
{
    BlockType stat_ex = BlockType::EXIT;
    const std::vector<Direction> directions = {Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT};

    if(current_status.left == stat_ex){
        delete turn_coord;
        return directions[2];
    }

    if(current_status.right == stat_ex) {
        delete turn_coord;
        return directions[3];
    }
    if (current_status.up == stat_ex){
        delete turn_coord;
        return directions[0];
    }
    if (current_status.down == stat_ex){
        delete turn_coord;
        return directions[1];
    }


    turn_coord = turn(angle);
    if(turn_coord->left == BlockType::WALL && turn_coord->up == BlockType ::FREE)
        return turn_directions();
    else if(turn_coord->left == BlockType::WALL && turn_coord->up == BlockType::WALL && turn_coord->right == BlockType ::FREE){
        int new_angle = -90;
        set_angle(new_angle);
        turn_coord = turn(angle);
        return turn_directions();
    }
    else if(turn_coord->left == BlockType::FREE) {
        int new_angle = 90;
        set_angle(new_angle);
        turn_coord = turn(angle);
        return turn_directions();
    }
    else {
        int new_angle = 180;
        set_angle(new_angle);
        turn_coord = turn(angle);
        return turn_directions();
    }

}



inline Status *Runner::turn(int angle)
{
    delete turn_coord;
    Status *temp = new Status;
    if(angle == 90) {
        temp->up = current_status.left;
        temp->left = current_status.down;
        temp->down = current_status.right;
        temp->right= current_status.up;
    }
    else if(angle == -90){
        temp->up = current_status.right;
        temp->left = current_status.up;
        temp->down  = current_status.left;
        temp->right = current_status.down;
    }
    else if(angle == 180){
        temp->up  = current_status.down;
        temp->left = current_status.right;
        temp->down = current_status.up;
        temp->right = current_status.left;
    }
    else {
        temp->left = current_status.left;
        temp->right = current_status.right;
        temp->down = current_status.down;
        temp->up = current_status.up;
    }
    return temp;
}


inline void Runner::set_angle(int new_angle)
{
    if(angle == 0)
        angle = new_angle;
    else if(angle == 90 && (new_angle == 90 || new_angle == -90))
        angle = angle + new_angle;
    else if(angle == 180 && new_angle == 90)
        angle = -90;
    else if(angle == 180 && new_angle == -90)
        angle = 90;
    else if(angle == -90 && (new_angle == 90))
        angle = 0;
    else if(angle == -90 && new_angle == -90)
        angle = 180;
    else if(new_angle == 180 && (angle == 90 || angle == -90))
        angle = -angle;
    else if(new_angle == 180 && angle == 180)
        angle = 0;
    else
        std::cout << "ERROR ANGLE" << new_angle << angle << std::endl;
}


inline Direction Runner::turn_directions()
{
    const std::vector<Direction> directions = {Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT};
    if(angle == 0)
        return directions[0];
    if(angle == 90)
        return directions[2];
    if(angle == -90)
        return directions[3];
    if(angle == 180)
        return directions[1];
    std::cout << "ERROR" << std::endl;
    return directions[0];
}