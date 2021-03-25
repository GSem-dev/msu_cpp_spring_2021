#include "allocator.hpp"
#include <iostream>
#include <cstddef>
#include <cassert>

int main()
{
    std::cout << "Test start"  << std::endl;
    Allocator al;
    std::cout << "Allocator created" << std::endl;
    al.makeAllocator(sizeof(char) * 20);
    assert(al.ptr != nullptr);
    std::cout << "Allocator with sizeof(char) * 7 memory" << std::endl;
    char* a = al.alloc(sizeof(char) * 7);
    assert(a != nullptr);
    char* b = al.alloc(sizeof(char) * 1);
    std::cout << "Allocated sizeof(char) * 1 memory" << std::endl;
    assert(b != nullptr);
    char* c = al.alloc(sizeof(char) * 15);
    std::cout << "Try allocate sizeof(char) * 15 memory" << std::endl;
    assert(c == nullptr);
    al.reset(); // перевыделили тот же размер
    char* d = al.alloc(sizeof(char) * 16);
    std::cout << "Reset an allocate szeof(char) * 16 memory" << std::endl;
    assert(d != nullptr);
    al.makeAllocator(sizeof(char) * 40);
    std::cout << "Remake allocator and  allocate sizeof(char) * 30 memory" << std::endl;
    char* e = al.alloc(sizeof(char) * 30);
    assert(e != nullptr);
    std::cout << std::endl;
    return 0;
}
