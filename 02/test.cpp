#include "parser.hpp"
#include <cassert>
#include <vector>
#include <typeinfo>
#include <cstring>

std::vector<std::string> array_str;
std::vector<unsigned long long> array_int;

void SimpleTest()
{   
    auto st = [](){std::cout<<"start"<<std::endl;};
    auto en = [](){std::cout<<"end"<<std::endl;};
    auto nu = [](unsigned long long n){std::cout<<"Number="<<n<<std::endl;};
    auto le = [](const std::string& s){std::cout<<"String:"<<s<<std::endl;};
    
    TokenParser prs {nu, le, st, en};
    
    prs.pars(" Hello \t world 12q 1234 ! \n 228");
}

void EmptyTest()
{    
    array_str.clear();
    array_int.clear();
    
    auto st = nullptr;
    auto en = nullptr;
    auto nu = [](unsigned long long n){array_int.push_back(n);};
    auto le = [](const std::string& s){array_str.push_back(s);};
    
    TokenParser prs {nu, le, st, en};
    
    prs.pars("");
    assert(array_str.empty());
    assert(array_int.empty());
    prs.pars(" \t \n      \t");
    prs.pars("\0");
    assert(array_str.empty());
    assert(array_int.empty());
}

void SingleStrTest()
{
    array_str.clear();
    array_int.clear();
    
    auto st = nullptr;
    auto en = nullptr;
    auto nu = [](unsigned long long n){array_int.push_back(n);};
    auto le = [](const std::string& s){array_str.push_back(s);};
    
    TokenParser prs {nu, le, st, en};
    prs.pars("1");
    assert(array_int[0] == 1);
    prs.pars("a");
    assert(array_str[0] == "a");
}

void TypeTest()
{
    array_str.clear();
    array_int.clear();
    
    auto st = nullptr;
    auto en = nullptr;
    auto nu = [](unsigned long long n){array_int.push_back(n);};
    auto le = [](const std::string& s){array_str.push_back(s);};
    
    TokenParser prs {nu, le, st, en};
    prs.pars("1");
    assert(array_int[0] == 1);
    prs.pars(" 121");
    prs.pars("0121 ");
    prs.pars("a");
    assert(array_str[0] == "a");
    prs.pars("1a");
    prs.pars(" 12131aa ");
    for (auto const &element: array_int)
    {
        assert(typeid(element).name() == typeid(unsigned long long).name());
    }
    for (auto const &element: array_str)
    {
        assert(typeid(element).name() == typeid(std::string).name());
    }
}

void EqualTest()
{
    array_str.clear();
    array_int.clear();
    
    auto st = nullptr; //[](){std::cout<<"start"<<std::endl;};
    auto en = nullptr; //[](){std::cout<<"end"<<std::endl;};
    auto nu = [](unsigned long long n){array_int.push_back(n);};
    auto le = [](const std::string& s){array_str.push_back(s);};
    
    TokenParser prs {nu, le, st, en};
    
    prs.pars("12 441 Hola parser2 \t \n\n1231un 11");
    std::vector<std::string> test_s {"Hola", "parser2", "1231un"};
    std::vector<unsigned long long> test_i {12, 441, 11};
    std::string s1;
    std::string s2;
    for (int i = 0; i < array_int.size(); i++)
    {
        assert(array_int[i] == test_i[i]);
    }
    for (int i = 0; i < array_str.size(); i++)
    {
        s1 = array_str[i];
        s2 = test_s[i];
        assert(s1 == s2);
    }
}

void Unit64Test()
{
    auto st = nullptr;
    auto en = nullptr;
    auto nu = [](unsigned long long n){std::cout<<"Number="<<n<<std::endl;};
    auto le = [](const std::string& s){std::cout<<"String:"<<s<<std::endl;};
    
    TokenParser prs {nu, le, st, en};
    
    prs.pars("18446744073709551616");
    prs.pars("18446744073709551615");
    prs.pars("18446744073709551614");
}

void IsDigitTest()
{
    array_str.clear();
    array_int.clear();
    
    auto st = nullptr; //[](){std::cout<<"start"<<std::endl;};
    auto en = nullptr; //[](){std::cout<<"end"<<std::endl;};
    auto nu = [](unsigned long long n){array_int.push_back(n);};
    auto le = [](const std::string& s){array_str.push_back(s);};
    
    TokenParser prs {nu, le, st, en};
    
    prs.pars("00000000000000000000011615");
    assert(array_int[0] == 11615);
}

void NumNullptrTest()
{
    auto st = nullptr;
    auto en = nullptr;
    auto nu = nullptr;
    auto le = [](const std::string& s){std::cout<<"String:"<<s<<std::endl;};
    
    TokenParser prs {nu, le, st, en};
    prs.pars("18446744073709551615\t c21");
}

void NullptrCallTest()
{    
    TokenParser prs {};
    prs.pars(" w dd ab c21 ");
}

int main()
{
    SimpleTest();
    EmptyTest();
    SingleStrTest();
    TypeTest();
    EqualTest();
    Unit64Test();
    IsDigitTest();
    NumNullptrTest();
    NullptrCallTest();
    std::cout<<"success"<<std::endl;
    return 0;
}
