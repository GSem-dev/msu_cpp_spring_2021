#include <iostream>
#include "pool.h"

#include <thread>
#include <pthread.h>

struct A {};

void foo(const A&) {}

int main(int argc, char* argv[])
{
    ThreadPool pool(8);
    auto task1 = pool.exec(foo, A());
    task1.get();

    auto task2 = pool.exec([]() { return 1; });
    task2.get();
    return 0;
}
