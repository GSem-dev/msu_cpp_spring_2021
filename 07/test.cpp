#include "Vector.h"
#include <chrono>
#include <iostream>
#include <cassert>
#include <deque>
#include <list>
#include <vector>

void OperatorTest()
{
    Vector<int> v;
    v.push_back(10);
    v.push_back(12);
    v.push_back(13);
    assert(v[1] == 12);
}

void PushTest()
{
    Vector<int> v;
    v.push_back(22);
    assert(!v.empty());
    assert(v.size() == 1);
}

void PopTest()
{
    Vector<int> v;
    v.push_back(22);
    auto x = v.pop_back();
    assert(v.empty());
    assert(x == 22);
    assert(v.size() == 0);
    v.push_back(32);
    v.push_back(42);
    assert(v.pop_back()== 42);
    assert(v.size() == 1);
}

void EmplaceTest()
{
    Vector<int> v;
    v.emplace_back(22);
    assert(!v.empty());
    assert(v.size() == 1);
}

void EmptyTest()
{
    Vector<int> v;
    assert(v.empty());
    v.push_back(10);
    assert(!v.empty());    
}

void SizeTest()
{
    Vector<int> v;
    assert(v.size() == 0);
    v.push_back(10);
    assert(v.size() == 1);
    v.push_back(12);
    v.push_back(13);
    assert(v.size() == 3);
    
}

void ClearTest()
{
    Vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    assert(v.size() == 3);
    v.clear();
    assert(v.size() == 0);    
}

void BegRbegTest()
{
    Vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    
    auto b = v.begin();
    assert(b != v.end());
    assert(*b == 0);
    ++b;
    assert(b != v.end());
    assert(*b == 1);
    ++b;
    assert(b != v.end());
    assert(*b == 2);
    ++b;
    assert(b == v.end());
    
    auto r = v.rbegin();
    assert(r != v.rend());
    assert(*r == 2);
    ++r;
    assert(r != v.rend());
    assert(*r == 1);
    ++r;
    assert(r != v.rend());
    assert(*r == 0);
    ++r;
    assert(r == v.rend());
}

void EndRendTest()
{
    Vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(0);
    
    auto b = v.end();
    assert(b != v.begin());
    --b;
    assert(b != v.begin());
    assert(*b == 0);
    --b;
    assert(b != v.begin());
    assert(*b == 1);
    --b;
    assert(b == v.begin());
    assert(*b == 2);
    
    auto r = v.rend();
    assert(r != v.rbegin());
    --r;    
    assert(r != v.rbegin());
    assert(*r == 2);
    --r;
    assert(r != v.rbegin());
    assert(*r == 1);
    --r;
    assert(r == v.rbegin());
    assert(*r == 0);
}

void ResizeTest()
{
    Vector<int> v;
    v.push_back(2);
    v.resize(10);
    assert(v.size() == 10);
}

void ReserveTest()
{
    Vector<int> v;
    v.push_back(2);
    v.push_back(33);
    v.push_back(21);
    v.reserve(100);
    assert(v.capacity() >= 100);
}

void CapacityTest()
{
    Vector<int> v;
    v.reserve(100);
    assert(v.capacity() >= 100);
}

int main()
{
    OperatorTest();
    PushTest();
    PopTest();
    EmplaceTest();
    EmptyTest();
    SizeTest();
    ClearTest();
    BegRbegTest();
    EndRendTest();
    ResizeTest();
    ReserveTest();
    CapacityTest();
    std::cout<<"Succes!"<<std::endl;
}
