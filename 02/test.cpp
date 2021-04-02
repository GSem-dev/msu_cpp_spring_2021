#include "parser.hpp"

void SampleTest()
{   
    auto st = [](){std::cout<<"start"<<std::endl;};
    auto en = [](){std::cout<<"end"<<std::endl;};
    auto nu = [](unsigned long long n){std::cout<<"Number="<<n<<std::endl;};
    auto le = [](const std::string& s){std::cout<<"String:"<<s<<std::endl;};
    
    TokenParser prs {nu, le, st, en};
    
    prs.pars(" Hello \t world 12q 1234");
}
void EmptyTest()
{   
    auto st = [](){std::cout<<"start"<<std::endl;};
    auto en = [](){std::cout<<"end"<<std::endl;};
    auto nu = [](unsigned long long n){std::cout<<"Number="<<n<<std::endl;};
    auto le = [](const std::string& s){std::cout<<"String:"<<s<<std::endl;};
    
    TokenParser prs {nu, le, st, en};
    
    prs.pars("");
    prs.pars(" \t \n ");
}

void Unit64Test()
{   
    auto st = [](){std::cout<<"start"<<std::endl;};
    auto en = [](){std::cout<<"end"<<std::endl;};
    auto nu = [](unsigned long long n){std::cout<<"Number="<<n<<std::endl;};
    auto le = [](const std::string& s){std::cout<<"String:"<<s<<std::endl;};
    
    TokenParser prs {nu, le, st, en};
    
    prs.pars("18446744073709551617");
    prs.pars("18446744073709551613");
}

int main()
{
    SampleTest();
    EmptyTest();
    Unit64Test();
    return 0;
}
