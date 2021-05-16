#include "Serializer.h"
#include <cassert>
#include <sstream>
#include <limits>

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

struct SingleUintData
{
    uint64_t a;

    template <class T>
    Error serialize(T& serializer)
    {
        return serializer(a);
    }
};

struct SingleBoolData
{
    bool a;

    template <class T>
    Error serialize(T& serializer)
    {
        return serializer(a);
    }
};

void BigInt()
{
    // не понял зачем это тест 
    // мы ведь работаем с uint64_t
    uint64_t my_max =  std::numeric_limits<uint64_t>::max() - 1;
    // std::cout << "max uint64 =" << my_max << std::endl; 
    
    SingleUintData x{std::numeric_limits<uint64_t>::max()-1}; // тут будет max - 1
    
    std::stringstream stream;
    Serializer serializer(stream);
    
    const Error rerr = serializer.save(x);
    assert(rerr == Error::NoError);
    assert(stream.str() == "18446744073709551614 ");
    SingleUintData y{0};
    Deserializer deserializer(stream);
    const Error lerr = deserializer.load(y);
    assert(lerr == Error::NoError);
    assert(y.a == my_max);
    assert(stream.str() == "18446744073709551614 ");
    
    stream.str(""); // очищаем
    stream << "18446744073709551619 "; // заполняем большим числом
    // max   = 18446744073709551615
    SingleUintData z{0};
    try
    {
        const Error error = deserializer.load(z);
        assert(error == Error::NoError);
        assert(false);
    } catch(const std::out_of_range &)
    {
        assert(true);
    }
}

void SingleBoolTets()
{
    SingleBoolData x{true};
    std::stringstream stream;
    Serializer serializer(stream);    
    const Error rerr = serializer.save(x);
    assert(rerr == Error::NoError);
    assert(stream.str() == "true ");
    SingleBoolData y{false};
    Deserializer deserializer(stream);
    const Error lerr = deserializer.load(y);
    assert(lerr == Error::NoError);
    assert(x.a == y.a);
    assert(stream.str() == "true ");
}

void SingleUintTest()
{
    SingleUintData x{12};
    std::stringstream stream;
    Serializer serializer(stream);    
    const Error rerr = serializer.save(x);
    assert(rerr == Error::NoError);
    assert(stream.str() == "12 ");
    SingleUintData y{2};
    Deserializer deserializer(stream);
    const Error err = deserializer.load(y);
    assert(err == Error::NoError);
    assert(x.a == y.a);
    assert(stream.str() == "12 ");
}

void InitTest() {
    Data x{1, true, 2};
    std::stringstream stream;
    Serializer serializer(stream);
    
    const Error rerr = serializer.save(x);
    assert(rerr == Error::NoError);
    assert(stream.str() == "1 true 2 ");
    
    Data y{0, false, 0 };
    Deserializer deserializer(stream);
    const Error err = deserializer.load(y);
    assert(err == Error::NoError);
    assert(x.a == y.a);
    assert(x.b == y.b);
    assert(x.c == y.c);
    assert(stream.str() == "1 true 2 ");
}

void ValidInvalidTest()
{
    SingleUintData x{true};
    std::stringstream stream;
    Serializer serializer(stream);    
    const Error rerr = serializer.save(x);
    assert(rerr == Error::NoError);
    assert(stream.str() == "1 ");
    
    SingleUintData y{0};
    Deserializer deserializer(stream);
    const Error err = deserializer.load(y);
    assert(err == Error::NoError);
    assert(x.a == y.a);
    assert(stream.str() == "1 ");
    
    Data c{ 0, 1, false};
    std::stringstream strm;
    Serializer serializer2(strm);
    
    const Error lerror = serializer2.save(c);
    assert(lerror == Error::NoError);
    assert(strm.str() == "0 true 0 ");
    
    Data d{true, false, 0 };
    Deserializer deserializer2(strm);
    const Error error = deserializer2.load(d);
    assert(error == Error::NoError);
    assert(c.a == d.a);
    assert(c.b == d.b);
    assert(c.c == d.c);
    assert(strm.str() == "0 true 0 ");
}

void MuchTest()
{
    SingleUintData x{true};
    std::stringstream stream;
    Serializer serializer(stream);    
    const Error rerr = serializer.save(x);
    assert(rerr == Error::NoError);
    assert(stream.str() == "1 ");   
    //std::cout << stream.str() << std::endl;
    stream << "false" << ' ' <<"false" << ' ';
    //std::cout << stream.str() << std::endl;
    
    SingleUintData y{0};
    Deserializer deserializer(stream);
    const Error err = deserializer.load(y);
    assert(err == Error::NoError);
    assert(x.a == y.a);
    assert(stream.str() == "1 false false ");
}

void FewTest()
{
    Data d{2, true, 3};
    std::stringstream in;
    Serializer serializer(in);
    const Error rerr = serializer.save(d);
    assert(rerr == Error::NoError);  
    std::string letters;
    in >> letters;
    in >> letters;
    in.str(""); // очищаем
    //std::cout << "1) in=" << in.str() << std::endl;
    in << "2 true "; // заполняем
    //std::cout << "2) in=" << in.str() << std::endl;
    Data c{1, false, 0};
    try
    {
        Deserializer deserializer(in);
        const Error err = deserializer.load(c);
        assert(err == Error::NoError);
        assert(false);
    } catch(const std::invalid_argument &)
    {
        assert(true);
    }
}

int main() {
    BigInt();
    InitTest();
    SingleBoolTets();
    SingleUintTest();
    ValidInvalidTest();
    MuchTest();
    FewTest();
    std::cout << "Success!" << std::endl;
    return 0;
}
