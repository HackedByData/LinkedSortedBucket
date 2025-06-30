#include <stdexcept>
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

struct OutOfBounds : std::out_of_range {
    OutOfBounds(const std::string& msg)
    : std::out_of_range(msg) { }

    OutOfBounds()
    : OutOfBounds("Index out of bounds error") { }
};

struct InvalidInput : std::runtime_error{
    InvalidInput(const std::string& msg)
    : std::runtime_error(msg) { }

    InvalidInput()
    : InvalidInput("Invalid Input") { }
};

#endif //EXCEPTIONS_H