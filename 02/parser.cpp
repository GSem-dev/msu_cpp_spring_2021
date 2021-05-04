#include <iostream>
#include <string>
#include "parser.hpp"
#include <algorithm>

bool is_digits(const std::string &str)
{
    if (str.empty()) return false;
    std::string clear_std = str.substr(str.find_first_not_of("0"));
    std::string max = "18446744073709551615";
    if (clear_std.size() > max.size()) return false;
    if (clear_std.size() == max.size() and  clear_std>max) return false;
    return clear_std.find_first_not_of("0123456789") == std::string::npos;
}
void TokenParser::SetStartCallback(trholds start_cb)
{
    Beg = start_cb;
}
void TokenParser::SetEndCallback(trholds end_cb)
{
    End = end_cb;
}
void TokenParser::SetDigitCallback(numbers num_cb)
{
    Num = num_cb;
}
void TokenParser::SetLettersCallback(letters let_cb)
{
    Let = let_cb;
}

void TokenParser::pars(const std::string &str)
{
    size_t pos = 0; // каретка
    size_t prev = 0;
    size_t pos2 = 0;
    std::string token;
    if (Beg != nullptr)
    {
        Beg();
    }
    do
    {
        prev = str.find_first_of(" \t\n", pos);
        pos2 = (prev!=std::string::npos) ? prev : str.size();
        token = str.substr(pos, pos2 - pos);
        if (is_digits(token))
        {
            std::string clear_std = token.substr(token.find_first_not_of("0"));
            unsigned long long number = std::stoull(clear_std);
            if (Num!=nullptr) Num(number); 
        }
        else if (token!="")
        {
            if (Let!=nullptr) Let(token);
        }
        pos = str.find_first_not_of(" \t\n", pos2);

    } while(prev != std::string::npos && pos != std::string::npos); // пока что то есть
    if (End)
    {
        End();
    }
}
