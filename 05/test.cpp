#include "Serializer.h"
#include <cassert>
#include <sstream>

struct Data
{
    uint64_t a;
    bool b;
    uint64_t c;

    template <class T>
    Error serialize(T& serializer)
    {
        return serializer(a, b, c);
    }
};

void InitTest() {
    Data x{ 1, true, 2 };
    std::stringstream stream;
    Serializer serializer(stream);
    serializer.save(x);
    Data y{ 0, false, 0 };
    Deserializer deserializer(stream);
    const Error err = deserializer.load(y);
    assert(err == Error::NoError);
    assert(x.a == y.a);
    assert(x.b == y.b);
    assert(x.c == y.c);
}

int main() {
    InitTest();
    return 0;
}
