#include "allocator.hpp"
#include <iostream>
#include <cstddef>
//#include <cstddef>
#include <cstdlib> 

int main()
{
    std::cout << "Для запуска теста необходимос запустить test" << std::endl;
    Allocator al;
    al.makeAllocator(sizeof(char));
    return 0;
}
