#include "Exceptions.h"

const char* IllegalPointerSetException::what() const throw()
{
    return "IllegalPointerSetException exception has been thrown.";
}
