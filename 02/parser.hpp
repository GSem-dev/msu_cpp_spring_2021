#pragma once 
#include <iostream>
#include <string>

class TokenParser
{
public:
    using numbers = void(*)(unsigned long long); // указатель на обработку чисел
    using letters = void(*)(const std::string&);
    using trholds = void(*)(); // обработка начала и конца
    
    numbers Num;
    letters Let;
    trholds Beg;
    trholds End;

    TokenParser(
        numbers cb_num = nullptr,\
        letters cb_let = nullptr,\
        trholds cb_beg = nullptr,\
        trholds cb_end = nullptr)
    {
        SetStartCallback(cb_beg);
        SetDigitCallback(cb_num);
        SetLettersCallback(cb_let);
        SetEndCallback(cb_end);
    }

    void SetStartCallback(trholds cb_beg);
    void SetDigitCallback(numbers cb_num);
    void SetLettersCallback(letters cb_let);
    void SetEndCallback(trholds cb_end);

    void pars(const std::string & str);
private:
};
