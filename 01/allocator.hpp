#pragma once
#include <cstddef>
#include <cstdlib>

class Allocator
{
public:
//    Allocator() = default;
    void makeAllocator(size_t maxSize);
    char* alloc(size_t size);
    void reset();
    char* ptr = nullptr; //  сам указатель на перый (0) элемент
    ~Allocator()
    {
         if(ptr) delete[] ptr;
    }

private:
    size_t _available_size = 0; //  максимально доступный размер
    size_t _used_size = 0; //  задействованный размер
};
