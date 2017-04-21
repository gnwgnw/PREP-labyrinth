#ifndef MYERROR_H
#define MYERROR_H

#include <iostream>
using std::string;

class MyError {
public:
    int errCode;
    const string errMessage;
    MyError(int code, const string& message): errCode(code), errMessage(message)
    {}
    ~MyError(){}
};

#endif //MYERROR_H
