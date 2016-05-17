//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"
#include <iostream>
#include <fstream>

using namespace std;

Runner::Runner()
{
    move_deadlock = 0;
    x = 3;
    y = 3;
    height_map = 3;
    width_map = 3;
    height_map_max = 7;
    width_map_max = 7;
    map_lab = new int*[height_map_max];
    for(int i = 0; i < height_map_max; i++)
        map_lab[i] = new int[width_map_max];
    map_lab[y][x] = 2;
}

Direction Runner::step()
{
    int flag = 0;
    draw_map();
   // Direction dir = Direction::UP;
    Direction dir = check_move();
    if (move_deadlock == 0)
        map_lab[y][x] = 4;
    else
    {
        if(map_lab[y][x] == -1)
        {
            while(flag == 0)
            {
                flag = 0;
                for(int i = 0; i < height_map_max; i++)
                {
                    for(int j = 0; j < width_map_max; j++)
                    {
                        if(map_lab[i][j] < 0 || map_lab[i][j] > 4)
                        {
                            map_lab[i][j] = 4;
                            flag = 1;
                        }
                    }
                }
                move_deadlock = 0;
            }
        }
        else
            map_lab[y][x] = -3;
    }
    if (y + 1 >= height_map_max / 2 + height_map / 2 || y - 1 <= height_map_max / 2 - height_map / 2
        || x + 1 >= width_map_max / 2 + width_map / 2  || x - 1 <= width_map_max / 2 - width_map / 2 )
    {
        height_map+= 2;
        width_map+= 2;
        for(int i = 0; i < height_map_max; i++)
        {
            for(int j = 0; j < width_map_max; j++)
            {
                if(map_lab[i][j]< -3 || map_lab[i][j]> 10000)
                {
                    map_lab[i][j] = 0;
                }
            }
        }

    }
//    fout.open("Map.txt");
//    fout << "31 30";
//    for(int i = height_map_max / 2 - height_map / 2; i < height_map_max / 2 + 1 + height_map / 2; i++)
//   {
//       for(int j = width_map_max / 2 - width_map / 2; j < width_map_max / 2 + 1 + width_map / 2; j++)
//       {
//           fout << map_lab[i][j] << " ";
//       }
//       fout << "\n";
//   }
//   fout.close();
    return dir;
}

Direction Runner::check_move()
{
    if(current_status.up == BlockType::EXIT)
        return Direction::UP;
    if(current_status.down == BlockType::EXIT)
        return Direction::DOWN;
    if(current_status.left == BlockType::EXIT)
        return Direction::LEFT;
    if(current_status.right == BlockType::EXIT)
        return Direction::RIGHT;
  //  print_map();
    Direction dir;

    if(map_lab[y - 1][x] == 0 || map_lab[y + 1][x] == 0 || map_lab[y][x - 1] == 0 || map_lab[y][x + 1] == 0)
    {
        if(map_lab[y + 1][x] == 0)
        {
            y++;
            dir = Direction::DOWN;
            return dir;
        }
        if(map_lab[y][x + 1] == 0)
        {
            x++;
            dir = Direction::RIGHT;
            return dir;
        }
        if(map_lab[y - 1][x] == 0)
        {
            y--;
            dir = Direction::UP;
            return dir;
        }
        if(map_lab[y][x - 1] == 0)
        {
            x--;
            dir = Direction::LEFT;
            return dir;
        }
    }

    if(move_deadlock == 0)
    {
    map_lab[y][x] = 5;

    int flag = 0;
    int flag1 = 0;
    int sp = 5;
    int x1;
    int y1;
    while(flag != 1)
    {
    //    print_map();
        flag1 = 0;
        for(int i = 0; i < height_map_max; i++)
        {
            for(int j = 0; j < width_map_max; j++)
            {
                if(map_lab[i][j] == sp)
                {
                    if(map_lab[i + 1][j] == 0)
                    {
                        flag = 1;
                        x1 = j;  y1 = i;
                    }
                    if(map_lab[i - 1][j] == 0 && flag == 0)
                    {
                        flag = 1;
                        x1 = j;  y1 = i;
                    }
                    if(map_lab[i][j + 1] == 0 && flag == 0)
                    {
                        flag = 1;
                        x1 = j;  y1 = i;
                    }
                    if(map_lab[i][j - 1] == 0 && flag == 0)
                    {
                        flag = 1;
                        x1 = j;  y1 = i;
                    }
                    if(map_lab[i + 1][j] == 4 && flag == 0)
                    {
                        map_lab[i + 1][j] = sp + 1;
                        flag1++;
                    }
                    if(map_lab[i - 1][j] == 4 && flag == 0)
                    {
                        map_lab[i - 1][j] = sp + 1;
                        flag1++;
                    }
                    if(map_lab[i][j + 1] == 4 && flag == 0)
                    {
                        map_lab[i][j + 1] = sp + 1;
                        flag1++;
                    }
                    if(map_lab[i][j - 1] == 4 && flag == 0)
                    {
                        map_lab[i][j - 1] = sp + 1;
                        flag1++;
                    }
                }
            }
        }
        if(flag1 == 0)
            sp++;

//            ofstream fout2;
//            fout2.open("Map2.txt");
//    fout2 << "31 30 \n";
//    for(int i = height_map_max / 2 - height_map / 2; i < height_map_max / 2 + 1 + height_map / 2; i++)
//   {
//       for(int j = width_map_max / 2 - width_map / 2; j < width_map_max / 2 + 1 + width_map / 2; j++)
//       {
//           fout2 << map_lab[i][j] << " ";
//       }
//       fout2 << "\n";
//   }
//   fout2.close();
    }
//    if(map_lab[x1 + 1][j] > 4 && map_lab[x1 + 1][j] < sp)
//    {
//       map_lab[i + 1][j] = sp + 1;
//       flag1++;
//    }
//    if(map_lab[i - 1][j] == 4 && flag == 0)
//    {
//       map_lab[i - 1][j] = sp + 1;
//       flag1++;
//    }
//    if(map_lab[i][j + 1] == 4 && flag == 0)
//    {
//       map_lab[i][j + 1] = sp + 1;
//       flag1++;
//    }
//    if(map_lab[i][j - 1] == 4 && flag == 0)
//    {
//       map_lab[i][j - 1] = sp + 1;
//       flag1++;
//    }

  //  sp--;
    flag = 0;
    map_lab[y1][x1] = -1;
 //   cout << sp;
    while(flag != 1)
    {
//      print_map();
    //    cout << sp;
        flag1 = 0;

                if(map_lab[y1 + 1][x1] == 5)
                {
                   map_lab[y1 + 1][x1] = -3;
                   flag = 1;
                }
                if(map_lab[y1 - 1][x1] == 5)
                {
                   map_lab[y1 - 1][x1] = -3;
                   flag = 1;
                }
                if(map_lab[y1][x1 + 1] == 5)
                {
                   map_lab[y1][x1 + 1] = -3;
                   flag = 1;
                }
                if(map_lab[y1][x1 - 1] == 5)
                {
                   map_lab[y1][x1 - 1] = -3;
                   flag = 1;
                }
                if(map_lab[y1 + 1][x1] < sp && map_lab[y1 + 1][x1] > 4 && flag == 0)
                {
                    map_lab[y1 + 1][x1] = -2;
                    y1 ++;
                    flag1 = 1; sp--;
                }
                if(map_lab[y1 - 1][x1] < sp && map_lab[y1 - 1][x1] > 4 && flag1 == 0 && flag == 0)
                {
                    map_lab[y1 - 1][x1] = -2;
                    y1 --;
                    flag1 = 1; sp--;
                }
                if(map_lab[y1][x1 + 1] < sp && map_lab[y1][x1 + 1] > 4 && flag1 == 0 && flag == 0)
                {
                    map_lab[y1][x1 + 1] = -2;
                    x1 ++;
                    flag1 = 1; sp--;
                }
                if(map_lab[y1][x1 - 1] < sp && map_lab[y1][x1 - 1] > 4 && flag1 == 0 && flag == 0)
                {
                    map_lab[y1][x1 - 1] = -2;
                    x1 --;
                    flag1 = 1; sp--;
                }

    }
        move_deadlock = 1;
 //       print_map();
    }

   // print_map();
    if(move_deadlock == 1)
    {
        if(map_lab[y + 1][x] == -1)
        {
            y++;
            dir = Direction::DOWN;
            return dir;
        }
        if(map_lab[y][x + 1] == -1)
        {
            x++;
            dir = Direction::RIGHT;
            return dir;
        }
        if(map_lab[y - 1][x] == -1)
        {
            y--;
            dir = Direction::UP;
            return dir;
        }
        if(map_lab[y][x - 1] == -1)
        {
            x--;
            dir = Direction::LEFT;
            return dir;
        }
        if(map_lab[y + 1][x] == -2)
        {
            y++;
            dir = Direction::DOWN;
            return dir;
        }
        if(map_lab[y][x + 1] == -2)
        {
            x++;
            dir = Direction::RIGHT;
            return dir;
        }
        if(map_lab[y - 1][x] == -2)
        {
            y--;
            dir = Direction::UP;
            return dir;
        }
        if(map_lab[y][x - 1] == -2)
        {
            x--;
            dir = Direction::LEFT;
            return dir;
        }
    }

}

void Runner::create_map_lab()
{
    int **map_lab2 = new int*[height_map_max];
    for(int i = 0; i < height_map_max; i++)
        map_lab2[i] = new int[width_map_max];

    for(int i = 0; i < height_map_max; i++)
    {
        for(int j = 0; j < width_map_max; j++)
        {
            map_lab2[i][j] = map_lab[i][j];
        }
    }

    height_map_max *= 2;
    width_map_max *= 2;
    height_map_max++;
    width_map_max++;
    x += (height_map_max / 4 + 1);
    y += (width_map_max / 4 + 1);

    map_lab = new int*[height_map_max];
    for(int i = 0; i < height_map_max; i++)
        map_lab[i] = new int[width_map_max];

    for(int i = height_map_max / 4 + 1; i < (height_map_max / 4 + 1) * 3 - 1; i++)
    {
        for(int j = width_map_max / 4 + 1; j < (width_map_max / 4 + 1) * 3 - 1; j++)
        {
            map_lab[i][j] = map_lab2[i - height_map_max / 4 - 1][j - width_map_max / 4 - 1];
        }
    }
}

void Runner::draw_map()
{
   if(height_map == height_map_max / 2 + 2)
        create_map_lab();

   if (current_status.up == BlockType::FREE && map_lab[y - 1][x] != 4 && map_lab[y - 1][x] == 0)
        map_lab[y - 1][x] = 0;
   if (current_status.down == BlockType::FREE && map_lab[y + 1][x] != 4 && map_lab[y + 1][x] == 0)
        map_lab[y + 1][x] = 0;
   if (current_status.left == BlockType::FREE && map_lab[y][x - 1] != 4 && map_lab[y][x - 1] == 0)
        map_lab[y][x - 1] = 0;
   if (current_status.right == BlockType::FREE && map_lab[y][x + 1] != 4 && map_lab[y][x + 1] == 0)
        map_lab[y][x + 1] = 0;

   if (current_status.up == BlockType::WALL)
        map_lab[y - 1][x] = 1;
   if (current_status.down == BlockType::WALL)
        map_lab[y + 1][x] = 1;
   if (current_status.left == BlockType::WALL)
        map_lab[y][x - 1] = 1;
   if (current_status.right == BlockType::WALL)
        map_lab[y][x + 1] = 1;
}

void Runner::print_map()
{
   cout << "\n\n Map \n";
   for(int i = height_map_max / 2 - height_map / 2; i < height_map_max / 2 + 1 + height_map / 2; i++)
   {
       for(int j = width_map_max / 2 - width_map / 2; j < width_map_max / 2 + 1 + width_map / 2; j++)
       {
           cout << map_lab[i][j] << " ";
       }
       cout << "\n";
   }
}
