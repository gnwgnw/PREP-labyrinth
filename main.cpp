#include <iostream>
#include <fstream>
#include <cstdio>
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

        freopen("out.txt", "w", stdout);
        field.result(cout);
        stdout = fdopen(0, "w");
        fprintf(stdout, "Total steps: 0, time: 0 mcs\n");
    }
    catch (ifstream::failure& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
