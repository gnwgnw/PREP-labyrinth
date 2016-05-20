#include <iostream>
#include <fstream>
#include "Field.hpp"


using std::cout;
using std::ifstream;

int main(int argc, char* argv[])
{
    if (argc != 2) {
        return 1;
    }

    ifstream file;
    std::ofstream fileOS;
    file.exceptions(ifstream::failbit | ifstream::badbit);

    try {
        Field field;


        fileOS.open(argv[1], std::ios_base::trunc | std::ios_base::out);
        fileOS << "7 7" << std::endl <<
        "1 1 1 1 1 1 1" << std::endl <<
        "1 2 3 0 0 0 1" << std::endl <<
        "1 0 0 0 1 1 1" << std::endl <<
        "1 0 1 0 0 0 1" << std::endl <<
        "1 0 1 1 1 0 1" << std::endl <<
        "1 0 0 0 1 1 1" << std::endl <<
        "1 1 1 1 1 1 1";
        fileOS.close();

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

    getchar();

    return 0;
}
