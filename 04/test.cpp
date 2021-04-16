#include "BigInt.h"
#include <iostream>
#include <limits>
#include <sstream>
#include <cassert>

void EqualTest()
{
    BigInt x = 3;
    assert(x == 3);
    BigInt y = x;
    assert(x == y);
    assert(y == 3);
    BigInt z;
    z = 0;
    assert(x != z);
}

void ShowTest()
{
    const BigInt big = std::numeric_limits<int64_t>::max();
    std::cout << big << std::endl;
}

int main()
{
    ShowTest();
    EqualTest();
    std::cout << "Finish!\n";

    return 0;
}
