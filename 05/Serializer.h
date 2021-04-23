#pragma once

#include<iostream>
#include <cmath>
#include <cstdio>
#include <cstring>

enum class Error
{
    NoError,
    CorruptedArchive
};

class Serializer
{
public:
    explicit Serializer(std::ostream& out)
        : out_(out)
    {
    }

    template <class T>
    Error save(T& object)
    {
        return object.serialize(*this);
    }

    template <class... ArgsT>
    Error operator()(ArgsT&... args)
    {
        return process(args...);
    }

    Error pro(bool value);
    Error pro(uint64_t);

private:
    std::ostream& out_;
    static constexpr char Separator = ' ';
    template <class T>
    Error process(T&& val)
    {
        return pro(val);
    }

    template <class T,class... Args>
    Error process(T&& val, Args&&... args)
    {
        if (pro(val) == Error::CorruptedArchive)
        {
            return Error::CorruptedArchive;
        }
        process(std::forward<Args>(args)...);
        return Error::NoError;
    }
};

class Deserializer
{
public:
    explicit Deserializer(std::istream& in)
        : in_(in)
    {
    }

    template <class T>
    Error load(T& object)
    {
        return object.serialize(*this);
    }

    template <class... ArgsT>
    Error operator()(ArgsT&... args)
    {
        return process(args...);
    }
    Error pro(uint64_t& val);
    Error pro(bool& val);
private:
    std::istream& in_;
    static constexpr char Separator = ' ';
    template <class T>
    Error process(T&& val)
    {
        return pro(val);
    }
    template <class T, class... Args>
    Error process(T&& val, Args&&... args)
    {
        if (process(val) == Error::CorruptedArchive)
        {
            return Error::CorruptedArchive;
        }
        process(std::forward<Args>(args)...);
        return Error::NoError;
    }
};
