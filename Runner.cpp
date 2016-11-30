//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"
#include <vector>
#include <cstdlib>
#include "utils.hpp"

Direction Runner::step()
{

    const std::vector<Direction> directions = {Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT};

    if(current_status.left == stat_ex){
        return directions[2];
    }
    if(current_status.right == stat_ex) {
        return directions[3];
    }
    if (current_status.up == stat_ex){
        return directions[0];
    }
    if (current_status.down == stat_ex){
        return directions[1];
    }

    turn(angle);

    if(turn_coord.left == BlockType::WALL && turn_coord.up == BlockType::FREE)
        return turn_directions();

    else if(turn_coord.left == BlockType::WALL && turn_coord.up == BlockType::WALL && turn_coord.right == BlockType ::FREE){
        set_angle(-90);
        turn(angle);
        return turn_directions();
    }

    else if(turn_coord.left == BlockType::FREE) {
        set_angle(90);
        turn(angle);
        return turn_directions();
    }

    else {
        set_angle(180);
        turn(angle);
        return turn_directions();
    }
}



void Runner::turn(short int angle)
{
    if(angle == 0)
    {
        turn_coord.left = current_status.left;
        turn_coord.right = current_status.right;
        turn_coord.down = current_status.down;
        turn_coord.up = current_status.up;
    }
    else if(angle == 90){
        turn_coord.up = current_status.left;
        turn_coord.left = current_status.down;
        turn_coord.down = current_status.right;
        turn_coord.right= current_status.up;
    }
    else if(angle == -90){
        turn_coord.up = current_status.right;
        turn_coord.left = current_status.up;
        turn_coord.down  = current_status.left;
        turn_coord.right = current_status.down;
    }
    else if(angle == 180){
        turn_coord.up  = current_status.down;
        turn_coord.left = current_status.right;
        turn_coord.down = current_status.up;
        turn_coord.right = current_status.left;
    }
}


inline void Runner::set_angle(short int new_angle)
{
    angle = (angle + new_angle);
    if(angle <= 180 && angle >=-90)
        ;
    else
        angle = angle + (angle > 180 ? -360 : 360);
//        angle = angle - 360;
//    else
//        angle = angle + 360;
//    if(angle == 0)
//        angle = new_angle;
//    else if(angle == 90 && (new_angle == 90 || new_angle == -90))
//        angle = angle + new_angle;
//    else if(angle == 180 && new_angle == 90)
//        angle = -90;
//    else if(angle == 180 && new_angle == -90)
//        angle = 90;
//    else if(angle == -90 && (new_angle == 90))
//        angle = 0;
//    else if(angle == -90 && new_angle == -90)
//        angle = 180;
//    else if(new_angle == 180 && (angle == 90 || angle == -90))
//        angle = -angle;
//    else if(new_angle == 180 && angle == 180)
//        angle = 0;
//    else
//        std::cout << "ERROR ANGLE" << new_angle << angle << std::endl;
}


inline Direction Runner::turn_directions()
{
    if(angle == 0)
        return directions[0];
    else if(angle == 90)
        return directions[2];
    else if(angle == -90)
        return directions[3];
    else
        return directions[1];
}