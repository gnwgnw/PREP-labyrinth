#include <iostream>
#include <fstream>
#include "Field.hpp"


using std::cout;
using std::ifstream;

int main(int argc, char* argv[])
{
   // argc = 2;
   // argv[1] = "/home/gri/Рабочий стол/тест/test_lab1.txt";
    if (argc != 2) {
        return 1;
    }

    ifstream file;
    file.exceptions(ifstream::failbit | ifstream::badbit);

    try {
        Field field;

        file.open(argv[1]);
        file >> field;

        while (!field.is_done()) {
            field.tic();
        }

        field.result(cout);
    }
    catch (ifstream::failure& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
