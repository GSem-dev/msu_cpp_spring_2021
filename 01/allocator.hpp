#pragma once
#include <cstddef>
#include <cstdlib>

class Allocator
{
public:
//    Allocator() = default;
    int makeAllocator();
    void makeAllocator(size_t maxSize);
    char* alloc(size_t size);
    void reset();
    char* ptr = nullptr; //  сам указатель на перый (0) элемент
    ~Allocator()
    {
         if(ptr) free(ptr);
    }

private:
    size_t _available_size = 0; //  максимально доступный размер
    size_t _used_size = 0; //  задействованный размер
};
