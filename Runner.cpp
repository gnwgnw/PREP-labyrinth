//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"

#include "vector"
#include "Runner.hpp"
#include "iostream"
#include "stack"
#include "cstdlib"
#include <ctime>


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


D Runner::step() {

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

        if (is_free(D::RIGHT)) {
            stack.top().right = true;
            stack.top().direction = D::RIGHT;

            Node node;
            node.left = true;

            stack.push(node);

            return D::RIGHT;
        }

        if (is_free(D::DOWN)) {
            stack.top().down = true;
            stack.top().direction = D::DOWN;

            Node node;
            node.up = true;

            stack.push(node);
            return D::DOWN;

            }

        if (is_free(D::LEFT)) {
            stack.top().left = true;
            stack.top().direction = D::LEFT;

            Node node;
            node.right = true;

            stack.push(node);
            return D::LEFT;
            }

        if (is_free(D::UP)) {
            stack.top().up = true;
            stack.top().direction = D::UP;

            Node node;
            node.down = true;

            stack.push(node);
            return D::UP;

            }
        }
    }
