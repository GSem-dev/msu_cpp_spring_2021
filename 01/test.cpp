#include "allocator.hpp"
#include <iostream>
#include <cstddef>
#include <cassert>

void DefaultWorkTest()
{
    Allocator all;
    all.makeAllocator(sizeof(char) * 10);
    assert(all.ptr != nullptr);
}

void SufficientSizeTest()
{
    Allocator all;
    all.makeAllocator(sizeof(char) * 10);
    char* a = all.alloc(sizeof(char) * 5);
    assert(a != nullptr);
}

void InsufficientSizeTest()
{
    Allocator all;
    all.makeAllocator(sizeof(char) * 10);
    char* a = all.alloc(sizeof(char) * 5);
    char* b = all.alloc(sizeof(char) * 15);
    assert(a != nullptr);
    assert(b == nullptr);
}

void ResetTest()
{
    Allocator all;
    all.makeAllocator(sizeof(char) * 10);
    all.reset();
    assert(all.ptr != nullptr);
}

void ReallocateTest()
{
    Allocator all;
    all.makeAllocator(sizeof(char) * 10);
    char* a = all.alloc(sizeof(char) * 7);
    char* b = all.alloc(sizeof(char) * 8);
    assert(a != nullptr);
    assert(b == nullptr);
    all.reset();
    char* c = all.alloc(sizeof(char) * 8);
    assert(c != nullptr);
}

void WorkTest()
{
    Allocator all;
    all.makeAllocator(sizeof(char));
    char* a = all.alloc(sizeof(char));
    *a = 'a';
    assert(*a == 'a');
    char* b = all.alloc(sizeof(char));
    assert(b == nullptr);
    all.reset();
    char* c = all.alloc(sizeof(char));
    *c = 'c';
    assert(*c == 'c');
}

int main()
{
    DefaultWorkTest();
    SufficientSizeTest();
    InsufficientSizeTest();
    ResetTest();
    ReallocateTest();
    WorkTest();

    std::cout<< "Success!\n";

    return 0;
}
