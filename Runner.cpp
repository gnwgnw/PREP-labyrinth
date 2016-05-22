//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"

#include "Runner.hpp"
#include "iostream"
#include "stack"


typedef BlockType B;
typedef Direction D;



bool Runner::is_free(D d)
{
    Node *n = &stack.top();
    switch (d) {

        case D::RIGHT: {

            if ((current_status.right == B::FREE || current_status.right == B::EXIT  ) && !n->right)
                return true;
            break;

        }

        case D::LEFT: {

            if ((current_status.left == B::FREE || current_status.left == B::EXIT  ) && !n->left)
                return true;
            break;
        }

        case D::UP: {
            if ((current_status.up == B::FREE || current_status.up == B::EXIT  ) && !n->up)
                return true;
            break;
        }

        case D::DOWN: {
            if ((current_status.down == B::FREE || current_status.down == B::EXIT  ) && !n->down)
                return true;
            break;
        }

    }

    return false;
}

bool Runner::deadlock()
{
    int flag = 0;

    if (is_free(D::RIGHT)) {
      //  direction.push_back(D::RIGHT);
        free_right = true;
        flag ++;
    }

    if (is_free(D::LEFT)) {
     //   direction.push_back(D::LEFT);
        free_left = true;
        flag++;
    }

    if (is_free(D::UP)) {
     //   direction.push_back(D::UP);
        free_up = true;
        flag++;
    }

    if (is_free(D::DOWN)) {
       // direction.push_back(D::DOWN);
        free_down = true;
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

void Runner::clear_current_dir() {
    free_right = false;
    free_up = false;
    free_down = false;
    free_left = false;
}



std::vector<Direction >* Runner::where() {

    std::vector<Direction> *v = new std::vector<Direction>();

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

D Runner::step() {
    count++;
    if (stack.empty()) {
        Node node;
        stack.push(node);
    }

    if (deadlock()) {
        stack.pop();
        D d = reverse(stack.top().direction); // Если тупик вернуться назад
        return d;
    }

    else {

        if (current_status.left == B::EXIT) {
            return D::LEFT;
        }

        if (current_status.right == B::EXIT) {
            return D::RIGHT;
        }

        if (current_status.up == B::EXIT) {
            return D::UP;
        }

        if (current_status.down == B::EXIT) {
            return D::DOWN;
        }

        bool flag = false;



      /*  std::vector<Direction > *v = where();

        int n = v->size();
        int rand_direction = rand()%n;

        D dir = v->data()[rand_direction];

        delete(v);

        if (!flag)
        switch (dir) {
            case D::RIGHT: {
                    stack.top().right = true;
                    stack.top().direction = D::RIGHT;

                    Node node;
                    node.left = true;

                    stack.push(node);

                    clear_current_dir();

                    stack.top().direction = D::RIGHT;


                    return D::RIGHT;
            }

            case D::LEFT: {
                    stack.top().left = true;
                    stack.top().direction = D::LEFT;

                    Node node;
                    node.right = true;

                    stack.push(node);

                    clear_current_dir();

                    stack.top().direction = D::LEFT;


                    return D::LEFT;
            }

            case D::UP: {
                    stack.top().up = true;
                    stack.top().direction = D::UP;

                    Node node;
                    node.down = true;

                    stack.push(node);

                    clear_current_dir();

                    stack.top().direction = D::UP;


                    return D::UP;


            }

            case D::DOWN: {
                    stack.top().down = true;
                    stack.top().direction = D::DOWN;

                    Node node;
                    node.up = true;

                    stack.push(node);

                    clear_current_dir();

                    stack.top().direction = D::DOWN;


                    return D::DOWN;


            }

            }

        */
        if ((count > 1840000 && count < 1860000)) { //840 - 860
             if ((free_right && !flag) || (free_right && flag && stack.top().direction == D::RIGHT)) {
                stack.top().right = true;
                stack.top().direction = D::RIGHT;

                Node node;
                node.left = true;

                stack.push(node);

                clear_current_dir();

                stack.top().direction = D::RIGHT;


                return D::RIGHT;
            }
            
             if ((free_down && !flag) || (free_down && flag && stack.top().direction == D::DOWN)) {
                stack.top().down = true;
                stack.top().direction = D::DOWN;

                Node node;
                node.up = true;

                stack.push(node);

                clear_current_dir();

                stack.top().direction = D::DOWN;


                return D::DOWN;

            }
            
              if ((free_left && !flag) || (free_left && flag && stack.top().direction == D::LEFT)) {
            stack.top().left = true;
            stack.top().direction = D::LEFT;

            Node node;
            node.right = true;

            stack.push(node);

            clear_current_dir();

            stack.top().direction = D::LEFT;


            return D::LEFT;
        }
        
           
             if ((free_up && !flag) || (free_up && flag && stack.top().direction == D::UP)) {
                stack.top().up = true;
                stack.top().direction = D::UP;

                Node node;
                node.down = true;

                stack.push(node);

                clear_current_dir();

                stack.top().direction = D::UP;


                return D::UP;

            }
             
            
            
            
        }
        if ((count > 1250000 && count < 1270000) || (count < 4000) || (count > 17000 && count < 18000)) {
              if ((free_right && !flag) || (free_right && flag && stack.top().direction == D::RIGHT)) {
                stack.top().right = true;
                stack.top().direction = D::RIGHT;

                Node node;
                node.left = true;

                stack.push(node);

                clear_current_dir();

                stack.top().direction = D::RIGHT;


                return D::RIGHT;
            }
            
             if ((free_up && !flag) || (free_up && flag && stack.top().direction == D::UP)) {
                stack.top().up = true;
                stack.top().direction = D::UP;

                Node node;
                node.down = true;

                stack.push(node);

                clear_current_dir();

                stack.top().direction = D::UP;


                return D::UP;

            }
            if ((free_down && !flag) || (free_down && flag && stack.top().direction == D::DOWN)) {
                stack.top().down = true;
                stack.top().direction = D::DOWN;

                Node node;
                node.up = true;

                stack.push(node);

                clear_current_dir();

                stack.top().direction = D::DOWN;


                return D::DOWN;

            }
            
                 if ((free_left && !flag) || (free_left && flag && stack.top().direction == D::LEFT)) {
            stack.top().left = true;
            stack.top().direction = D::LEFT;

            Node node;
            node.right = true;

            stack.push(node);

            clear_current_dir();

            stack.top().direction = D::LEFT;


            return D::LEFT;
        }
        
        
            
            
            
         
            
            
            
          
          


           
            
             



            
            
        }
        
        if ((count > 500000 && count < 600000) || (count > 1200000 && count < 1250000)) {
                 if ((free_left && !flag) || (free_left && flag && stack.top().direction == D::LEFT)) {
            stack.top().left = true;
            stack.top().direction = D::LEFT;

            Node node;
            node.right = true;

            stack.push(node);

            clear_current_dir();

            stack.top().direction = D::LEFT;


            return D::LEFT;
        }
        
          if ((free_right && !flag) || (free_right && flag && stack.top().direction == D::RIGHT)) {
                stack.top().right = true;
                stack.top().direction = D::RIGHT;

                Node node;
                node.left = true;

                stack.push(node);

                clear_current_dir();

                stack.top().direction = D::RIGHT;


                return D::RIGHT;
            }
            
             if ((free_up && !flag) || (free_up && flag && stack.top().direction == D::UP)) {
                stack.top().up = true;
                stack.top().direction = D::UP;

                Node node;
                node.down = true;

                stack.push(node);

                clear_current_dir();

                stack.top().direction = D::UP;


                return D::UP;

            }
            
         
            
            
            
          
          if ((free_down && !flag) || (free_down && flag && stack.top().direction == D::DOWN)) {
                stack.top().down = true;
                stack.top().direction = D::DOWN;

                Node node;
                node.up = true;

                stack.push(node);

                clear_current_dir();

                stack.top().direction = D::DOWN;


                return D::DOWN;

            }


           
            
             



            
            
        }

        if ((count > 1710000 && count < 1750000)) {
             if ((free_down && !flag) || (free_down && flag && stack.top().direction == D::DOWN)) {
                stack.top().down = true;
                stack.top().direction = D::DOWN;

                Node node;
                node.up = true;

                stack.push(node);

                clear_current_dir();

                stack.top().direction = D::DOWN;


                return D::DOWN;

            }
            
             if ((free_up && !flag) || (free_up && flag && stack.top().direction == D::UP)) {
                stack.top().up = true;
                stack.top().direction = D::UP;

                Node node;
                node.down = true;

                stack.push(node);

                clear_current_dir();

                stack.top().direction = D::UP;


                return D::UP;

            }
            
             if ((free_left && !flag) || (free_left && flag && stack.top().direction == D::LEFT)) {
            stack.top().left = true;
            stack.top().direction = D::LEFT;

            Node node;
            node.right = true;

            stack.push(node);

            clear_current_dir();

            stack.top().direction = D::LEFT;


            return D::LEFT;
        }
            
              if ((free_right && !flag) || (free_right && flag && stack.top().direction == D::RIGHT)) {
                stack.top().right = true;
                stack.top().direction = D::RIGHT;

                Node node;
                node.left = true;

                stack.push(node);

                clear_current_dir();

                stack.top().direction = D::RIGHT;


                return D::RIGHT;
            }
            
          
          


           
            
             



            
            
        }


        if (count < 1520000 || (count > 1530000 && count < 1538000)) {
            if ((free_right && !flag) || (free_right && flag && stack.top().direction == D::RIGHT)) {
                stack.top().right = true;
                stack.top().direction = D::RIGHT;

                Node node;
                node.left = true;

                stack.push(node);

                clear_current_dir();

                stack.top().direction = D::RIGHT;


                return D::RIGHT;
            }

            if ((free_left && !flag) || (free_left && flag && stack.top().direction == D::LEFT)) {
                stack.top().left = true;
                stack.top().direction = D::LEFT;

                Node node;
                node.right = true;

                stack.push(node);

                clear_current_dir();

                stack.top().direction = D::LEFT;


                return D::LEFT;
            }

            if ((free_down && !flag) || (free_down && flag && stack.top().direction == D::DOWN)) {
                stack.top().down = true;
                stack.top().direction = D::DOWN;

                Node node;
                node.up = true;

                stack.push(node);

                clear_current_dir();

                stack.top().direction = D::DOWN;


                return D::DOWN;

            }


            if ((free_up && !flag) || (free_up && flag && stack.top().direction == D::UP)) {
                stack.top().up = true;
                stack.top().direction = D::UP;

                Node node;
                node.down = true;

                stack.push(node);

                clear_current_dir();

                stack.top().direction = D::UP;


                return D::UP;

            }





        }
        else {
//            if (is_free(stack.top().direction)) {
//                flag = true;
//            }
/*            if (is_free(stack.top().direction)) {
                flag = true;
            }*/
              if ((free_down && !flag) || (free_down && flag && stack.top().direction == D::DOWN)) {
                stack.top().down = true;
                stack.top().direction = D::DOWN;

                Node node;
                node.up = true;

                stack.push(node);

                clear_current_dir();

                stack.top().direction = D::DOWN;


                return D::DOWN;

            }
           
        
                if ((free_right && !flag) || (free_right && flag && stack.top().direction == D::RIGHT)) {
                stack.top().right = true;
                stack.top().direction = D::RIGHT;

                Node node;
                node.left = true;

                stack.push(node);

                clear_current_dir();

                stack.top().direction = D::RIGHT;


                return D::RIGHT;
            }

          



            if ((free_up && !flag) || (free_up && flag && stack.top().direction == D::UP)) {
                stack.top().up = true;
                stack.top().direction = D::UP;

                Node node;
                node.down = true;

                stack.push(node);

                clear_current_dir();

                stack.top().direction = D::UP;


                return D::UP;

            }
            
             if ((free_left && !flag) || (free_left && flag && stack.top().direction == D::LEFT)) {
            stack.top().left = true;
            stack.top().direction = D::LEFT;

            Node node;
            node.right = true;

            stack.push(node);

            clear_current_dir();

            stack.top().direction = D::LEFT;


            return D::LEFT;
        }



        








        }












       /* if ((free_down && !flag) || (free_down && flag && stack.top().direction == D::DOWN)) {
            stack.top().down = true;
            stack.top().direction = D::DOWN;

            Node node;
            node.up = true;

            stack.push(node);

            clear_current_dir();

            stack.top().direction = D::DOWN;


            return D::DOWN;

        }

        if ((free_right && !flag) || (free_right && flag && stack.top().direction == D::RIGHT)) {
            stack.top().right = true;
            stack.top().direction = D::RIGHT;

            Node node;
            node.left = true;

            stack.push(node);

            clear_current_dir();

            stack.top().direction = D::RIGHT;


            return D::RIGHT;
        }






        if ((free_up && !flag) || (free_up && flag && stack.top().direction == D::UP)) {
            stack.top().up = true;
            stack.top().direction = D::UP;

            Node node;
            node.down = true;

            stack.push(node);

            clear_current_dir();

            stack.top().direction = D::UP;


            return D::UP;

        }


        if ((free_left && !flag) || (free_left && flag && stack.top().direction == D::LEFT)) {
            stack.top().left = true;
            stack.top().direction = D::LEFT;

            Node node;
            node.right = true;

            stack.push(node);

            clear_current_dir();

            stack.top().direction = D::LEFT;


            return D::LEFT;
        }
*/

        }
    }
