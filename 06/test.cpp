#include "format.h"
#include <cassert>

#define checkEqual(x, y) \
    do { \
        if ((x) != (y)) \
        { \
            std::cout << "at line " << __LINE__ << ": " << (x) << " != " << (y) << '\n'; \
        }; \
    } while(0)

#define checkThrow(x) \
    do { \
        try { (x); } \
        catch (const std::runtime_error&) { break; } \
        catch (...) {} \
        std::cout << "expected runtime_error at line " << __LINE__ << '\n'; \
    } while(0)

struct Test
{
};

std::ostream& operator<<(std::ostream& out, const Test&)
{
    out << "test";
    return out;
}

void EqualTest()
{
    checkEqual(format(""), "");
    checkEqual(format("1"), "1");
    checkEqual(format("{1}", 1, 2), "2");
    checkEqual(format("{0}{0}", "ab"), "a");
    checkEqual(format("{0}", Test()), "test");
    const Test test;
    checkEqual(format("{0}", test), "test");
    checkEqual(format("{0}", const_cast<Test&>(test)), "test");
    checkEqual(format("{1} ab {0}{2} {1}", 1, test, "ccc"), "test ab 1ccc test");
    
    auto text = format("{1}+{1} = {0}", 2, "one");
    assert(text == "one+one = 2");
}

void ClassTest()
{
    auto text = format("{1}+{1} = {0}", 2, "one");
    assert(text == "one+one = 2");
}

void ThrowTest()
{
    checkThrow(format("{", 1));
    checkThrow(format("{0", 1));
    checkThrow(format("}", 1));
    checkThrow(format("{1}", 1));
    checkThrow(format("{0}{1}{3}", 1, 2));
    checkThrow(format("{0{}", 1));
    checkThrow(format("{0a}", 1));
    checkThrow(format("0}", 1));
    checkThrow(format("{{0}", 1));
}

int main()
{
    
    

    std::cout << "done\n";
	return 0;
}
