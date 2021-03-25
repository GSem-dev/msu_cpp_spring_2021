#include "allocator.hpp"
#include <cstddef>
#include <cstdlib>

#include <iostream>

int Allocator::makeAllocator()
{
    return 11;
}
void Allocator::makeAllocator(size_t maxSize)
{
    if (ptr) free(ptr); // если уже что то выделенно, стираем и выделяем снова
    _available_size = maxSize;
    _used_size = 0;
    ptr = (char*)malloc(sizeof(char) * _available_size); //  выделяем нужный размер
}
char* Allocator::alloc(size_t size)
{
    if (ptr && (size + _used_size <= _available_size))
    {
        char* new_ptr = ptr + _used_size;
        _used_size += size;
        return new_ptr;
    }
    else
    {
        std::cout << "No size: "<< size<<"+"<< _used_size << ">"<< _available_size << std::endl;
        return nullptr;
    }
}
void Allocator::reset()
{
    // Полность очистить или перевыделить?
    free(ptr);
    _used_size = 0;
    ptr = (char*)malloc(sizeof(char) * _available_size); //  выделяем нужный размер
    return;
}
