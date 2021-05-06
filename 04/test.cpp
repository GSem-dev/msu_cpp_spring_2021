#include "BigInt.hpp"
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
    int n = 5;
    z = n;
    assert(x != z);
}

void MaxTest()
{
    const BigInt big = std::numeric_limits<int32_t>::max();
    assert(big == std::numeric_limits<int32_t>::max());
}

void StrTest()
{
    BigInt x("-11");
    assert(x == -11);
    BigInt s = 12;
    BigInt z;
    z = x+s;
    assert(z == 1);
}

void PlusTest()
{
    BigInt x = 4;
    BigInt z = 3;
    z = z + x + 3;
    assert(z == 10);
}

void MinusTest()
{
    BigInt x = 4;
    BigInt z = 3;
    z = x - 3;
    assert(z == 1);
}

void CompareTest()
{
    BigInt x = 4;
    BigInt z = 3;
    assert(x > z);
    assert(z < x);
    BigInt y = 3;
    assert(y <= z);
}

void UnoMinusTets()
{
    BigInt x = 4;
    x = -x;
    assert(x == -4);
}

void MoveTest()
{
    BigInt c = 4;
    BigInt d;
    d = std::move(c);
    assert(d == 4);
}

void CopyTest()
{
    BigInt c(4);
    BigInt d(c);
    BigInt a;
    a = d;
    BigInt b;
    a = BigInt("123");
    b = 1111;
}

void MullTest()
{
    BigInt a = 1;
    BigInt c = 4;
    BigInt d = -11;
    BigInt e = d * c;
    BigInt f = c * 3;
    assert(e == -44);
    assert(f == 12);
    f = a * c;
    assert(f == 4);
}

void ClassTest()
{
    BigInt a = 1;
    BigInt b("123456789012345678901234567890");
    BigInt c = a * b + 2;
    BigInt d;
    d = std::move(c);
    a = d + b;
    std::cout << a << std::endl;
}

void InterestingTest()
{
    BigInt a = 1;
    BigInt b("99999999");
    BigInt c = a + b;
    assert(a+b == 100000000);
}


int main()
{
    EqualTest();
    MaxTest();
    StrTest();
    PlusTest();
    CompareTest();
    UnoMinusTets();
    MinusTest();
    MoveTest();
    CopyTest();
    MullTest();
    ClassTest();
    InterestingTest();
    std::cout << "Succes!\n";
    return 0;
}
