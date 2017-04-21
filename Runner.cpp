#include "Runner.hpp"
#include <vector>
#include <cstdlib>
#include "utils.hpp"


Direction Runner::step() {

    if((current_status.right == BlockType::FREE || current_status.right == BlockType::EXIT) && (!path[foo(x+1,y)]){
       ++x;
      path[foo(x,y)]=1;
      return Direction::RIGHT;
    }
    if((current_status.up == BlockType::FREE || current_status.up == BlockType::EXIT) && (!path[foo(x,y+1)]){
      ++y;
      path[foo(x,y)]=1;
      return Direction::UP;
    }
    if((current_status.left == BlockType::FREE || current_status.left == BlockType::EXIT) && (!path[foo(x-1,y)]){
      --x;
      path[foo(x,y)]=1;
      return Direction::LEFT;
    }
    if((current_status.down == BlockType::FREE || current_status.down == BlockType::EXIT) && (!path[foo(x,y-1)]){
      --y;
      path[foo(x,y)]=1;
      return Direction::DOWN;
    }
    if(current_status.right == BlockType::FREE || current_status.right == BlockType::EXIT) {
      ++x;
      return Direction::RIGHT;
    }
    if(current_status.up == BlockType::FREE || current_status.up == BlockType::EXIT) {
      ++y;
      return Direction::UP;
    }
    if(current_status.left == BlockType::FREE || current_status.left == BlockType::EXIT) {
      --x;
      return Direction::LEFT;
    }
    if(current_status.down == BlockType::FREE || current_status.down == BlockType::EXIT) {
      --y;
      return Direction::DOWN;
    }



}
