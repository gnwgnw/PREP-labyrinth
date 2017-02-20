#include "Runner.hpp"

Direction Runner::step() {

    if (current_status.up == BlockType::EXIT) {
        return Direction::UP;
    }
    if (current_status.left == BlockType::EXIT) {
        return Direction::LEFT;
    }
    if (current_status.right == BlockType::EXIT) {
        return Direction::RIGHT;
    }
    if (current_status.down == BlockType::EXIT) {
        return Direction::DOWN;
    }

    if (prevStep == Direction::LEFT){

        if (current_status.down == BlockType::FREE){
            prevStep = Direction::DOWN;
            return Direction::DOWN;
        }

        if (current_status.left == BlockType::FREE){
            prevStep = Direction::LEFT;
            return Direction::LEFT;
        }

        if (current_status.up == BlockType::FREE){
            prevStep = Direction::UP;
            return Direction::UP;
        }

        if (current_status.right == BlockType::FREE){
            prevStep = Direction::RIGHT;
            return Direction::RIGHT;

        }
    }

    if (prevStep == Direction::UP) {

        if (current_status.left == BlockType::FREE){
            prevStep = Direction::LEFT;
            return Direction::LEFT;
        }

        if (current_status.up == BlockType::FREE){
            prevStep = Direction::UP;
            return Direction::UP;
        }

        if (current_status.right == BlockType::FREE){
            prevStep = Direction::RIGHT;
            return Direction::RIGHT;
        }

        if (current_status.down == BlockType::FREE){
            prevStep = Direction::DOWN;
            return Direction::DOWN;
        }
    }



    if (prevStep == Direction::RIGHT){
        if (current_status.up == BlockType::FREE){
            prevStep = Direction::UP;
            return Direction::UP;
        }

        if (current_status.right == BlockType::FREE){
            prevStep = Direction::RIGHT;
            return Direction::RIGHT;

        }

        if (current_status.down == BlockType::FREE){
            prevStep = Direction::DOWN;
            return Direction::DOWN;
        }

        if (current_status.left == BlockType::FREE){
            prevStep = Direction::LEFT;
            return Direction::LEFT;
        }
    }




    if (prevStep == Direction::DOWN) {
        if (current_status.right == BlockType::FREE){
            prevStep = Direction::RIGHT;
            return Direction::RIGHT;
        }

        if (current_status.down == BlockType::FREE){
            prevStep = Direction::DOWN;
            return Direction::DOWN;
        }
        if (current_status.left == BlockType::FREE){
            prevStep = Direction::LEFT;
            return Direction::LEFT;
        }



        if (current_status.up == BlockType::FREE){
            prevStep = Direction::UP;
            return Direction::UP;
        }
    }

return prevStep;
}
