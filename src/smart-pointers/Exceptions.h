#pragma once
#include <exception>

class IllegalPointerSetException : public std::exception
{
private:
    virtual const char* what() const throw();
};
