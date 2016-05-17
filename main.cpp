#include <iostream>
#include <fstream>
#include "Field.hpp"

namespace H
{
class Field;
std::istream& operator>>(std::istream& is, Field& field);
class Field
{
public:

    friend std::istream& operator>>(std::istream& is, Field& field);
     size_t tic_count = 0;
    void tic() {};
    bool is_done()
    {
        return true;
    };
    void result(std::ostream& os)
    {
        os << "Total steps: " << tic_count << std::endl;
    }
};
std::istream& operator>>(std::istream& is, Field& field) {};
}

using std::cout;
using std::ifstream;

#define Field H::Field

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        return 1;
    }
    ifstream file;
    file.exceptions(ifstream::failbit | ifstream::badbit);

    try
    {
        Field field;

        file.open(argv[1]);
        file >> field;

        while (!field.is_done())
        {
            field.tic();
        }

        field.result(cout);
    }
    catch (ifstream::failure& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
