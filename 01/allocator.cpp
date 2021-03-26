#include "allocator.hpp"
#include <cstddef>
#include <cstdlib>

#include <iostream>

void Allocator::makeAllocator(size_t maxSize)
{
    if (ptr) delete ptr; // если уже что то выделенно, стираем и выделяем снова
    _available_size = maxSize;
    _used_size = 0;
    ptr = new char(_available_size); //  выделяем нужный размер
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
    // поменять внутренне состояние аллокатора

    // сбросить все?
    // _available_size = 0;
    // _used_size = 0;
    // ptr = nullptr; // в этом случае нужно очищать

    // или обнулить использованный размер?
    _used_size = 0;
    return;
}
