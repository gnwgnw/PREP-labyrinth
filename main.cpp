#include <iostream>
#include <fstream>
#include "Field.hpp"


using std::cout;
using std::ifstream;

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cerr << "usage: " << argv[0] << " labyrinth.txt" << std::endl;
        return 1;
    }

    ifstream file;
    file.exceptions(ifstream::failbit | ifstream::badbit);

    try {
        Field field;

        file.open(argv[1]);
        file >> field;

        field.start();


        while (!field.is_done()) {
            if (!field.tic())
                return 1;
        }

        field.result(cout);
    }
    catch (ifstream::failure& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
