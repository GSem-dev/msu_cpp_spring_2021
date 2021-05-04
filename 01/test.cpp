#include "allocator.hpp"
#include <iostream>
#include <cstddef>
#include <cassert>
#include <exception>
#include <stdexcept> 

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
    all.makeAllocator(sizeof(char)*2);
    char* a = all.alloc(sizeof(char));
    *a = 'a';
    char* b = all.alloc(sizeof(char));
    *b = 'b';
    assert(*a == 'a');
    assert(*b == 'b');
    all.reset();
    char* c = all.alloc(sizeof(char));
    *c = 'c';
    assert(*c == 'c');
    assert(*b == 'b');
    char* d = all.alloc(sizeof(char)*5);
    assert(d == nullptr);
}

void MultipleMakeAlloc()
{
    Allocator all;
    all.makeAllocator(sizeof(char));
    char* a = all.alloc(sizeof(char));
    *a = 'a';
    assert(*a == 'a');
    char* ab = all.alloc(sizeof(char));
    assert(ab == nullptr);
    all.makeAllocator(sizeof(char)*2);
    char* b = all.alloc(sizeof(char));
    *b = 'b';
    char* c = all.alloc(sizeof(char));
    *c = 'c';
    assert(*c == 'c');
    assert(*b == 'b');
}

void AllocBeforeMake()
{
    Allocator all;
    char* a = all.alloc(sizeof(char));
    assert(a == nullptr);
    all.makeAllocator(sizeof(char));
    a = all.alloc(sizeof(char));
    *a = 'a';
    assert(*a == 'a');    
}

int main()
{
    DefaultWorkTest();
    SufficientSizeTest();
    InsufficientSizeTest();
    ResetTest();
    ReallocateTest();
    WorkTest();
    MultipleMakeAlloc();
    AllocBeforeMake();
    std::cout<<"success"<<std::endl;
    return 0;
}
