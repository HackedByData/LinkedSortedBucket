#include <iostream>

#ifndef TEST_H
#define TEST_H

#define FAIL "\033[1;31mFAIL: "
#define PASS "\033[1;32mPASS: "
#define COLOR_OFF "\033[0m"


void testTrue(bool predicate, const std::string& msg)
{
    std::cout << ((predicate)
    ? PASS 
    : FAIL ) << COLOR_OFF << msg << std::endl;
}

void testFalse(bool predicate, const std::string& msg)
{
    testTrue(!predicate, msg);

}

#endif