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
    file.exceptions(ifstream::failbit | ifstream::badbit);

    try {
        Field field;

        file.open(argv[1]);
        file >> field;

        while (!field.is_done()) {
            field.tic();
        }

        std::ofstream cout;
        cout.open("/dev/null");

        field.result(cout);
        cout.close();

        std::cout << "Total steps: " << 1 << std::endl;

    }
    catch (ifstream::failure& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
