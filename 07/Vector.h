#pragma once
#include <iterator>
#include <memory>
#include <iostream>
#include <exception>
#include <iterator>
#include <limits>

template <class T>
class Iterator : public std::iterator<std::random_access_iterator_tag, T>
{
public:
    using pointer = T*;
    using reference = T&;
    using iterator = Iterator<T>;
    using diff = std::ptrdiff_t;

private:
    pointer ptr_;

public:
    Iterator(pointer ptr)
        : ptr_(ptr)
    {
    }

    operator pointer()
    {
        return ptr_;
    }

    reference operator*()
    {
        return *ptr_;
    }

    reference operator[](diff n)
    {
        return *(ptr_ + n);
    }

    iterator& operator++()
    {
        ptr_++;
        return *this;
    }

    iterator& operator--()
    {
        ptr_--;
        return *this;
    }

    iterator& operator+=(diff n)
    {
        ptr_ += n;
        return *this;
    }

    iterator& operator-=(diff n)
    {
        ptr_ -= n;
        return *this;
    }

    iterator operator+(diff n) const
    {
        return iterator(ptr_ + n);
    }

    iterator operator-(diff n) const
    {
        return iterator(ptr_ - n);
    }

    iterator::diff operator-(const iterator& it) const
    {
        return ptr_ - it.ptr_;
    }

    bool operator==(const iterator& it) const
    {
        return ptr_ == it.ptr_;
    }
    bool operator!=(const iterator& it) const
    {
        return ptr_ != it.ptr_;
    }
};

template <class T>
struct Allocator
{
    using pointer = T*;
    pointer allocate(size_t count)
    {
        pointer new_data = static_cast<pointer>(malloc(sizeof(T) * count));
        if (new_data == nullptr) throw std::bad_alloc();
        return new_data;
    }

    void deallocate(pointer p, size_t count) noexcept
    {
        free(p);
    }

    template <typename... Args>
    void construct(pointer np, Args&&... args)
    {
        new (np) T(std::forward<Args>(args)...);
    }

    void destroy(pointer np) noexcept
    {
        np->~T();
    }
};


template <class T, class Alloc = Allocator<T>>
class Vector
{
    Alloc alloc;
    size_t size_;
    T* data;
public:
    using iterator = Iterator<T>;
    using reverse_iterator = std::reverse_iterator<Iterator<T>>;
private:
    iterator start, finish;
public:
    Vector()
        : size_(0)
        , data(alloc.allocate(size_))
        , start(data)
        , finish(data)
    {
    }

    T& operator[](std::ptrdiff_t i)
    {
        return data[i];
    }

    void push_back(const T& value)
    {
        if (size() >= size_)
        {
            reserve(size_ * 2 + 1);
        }
        alloc.construct(finish, value);
        ++finish;
    }

    template <typename... Args>
    void emplace_back(Args&&... args)
    {
        if (size() >= size_)
        {
            reserve(size_ * 2 + 1);
        }
        alloc.construct(finish, std::forward<Args>(args)...);
        ++finish;
    }

    T pop_back()
    {
        T tmp = data[size() - 1];
        if (size() > 0)
        {
            --finish;
            alloc.destroy(finish);
        }
        return tmp;
    }

    bool empty() const
    {
        return start == finish;
    }

    size_t size() const
    {
        return finish - start;
    }

    size_t capacity() const
    {
        return size_;
    }

    void clear()
    {
        resize(0);
    }

    iterator begin()
    {
        return start;
    }

    iterator end()
    {
        return finish;
    }

    reverse_iterator rbegin()
    {
        return reverse_iterator(finish);
    }

    reverse_iterator rend()
    {
        return reverse_iterator(start);
    }

    void resize(size_t new_size)
    {
        if (size_ < new_size) reserve(new_size);
        iterator prev = finish;
        finish = start + new_size; 
        while (prev > finish)
        {
            --prev;
            alloc.destroy(prev);
        }
        while (prev < finish)
        {
            alloc.construct(prev, T());
            ++prev;
        }
    }

    void reserve(size_t new_size)
    {
        if (new_size > size_)
        {
            size_t sz = size();
            T* mem = alloc.allocate(new_size);
            for (size_t i = 0; i < sz; ++i)
            {
                alloc.construct(mem + i, std::move(data[i]));
                alloc.destroy(data + i);
            }
            alloc.deallocate(data, size_);
            size_ = new_size;
            data = mem;
            start = iterator(data);
            finish = start + sz;
        }
    }

    ~Vector()
    {
        for (T* ptr = data; ptr < data + size(); ++ptr)
        {
            alloc.destroy(ptr);
        }
        alloc.deallocate(data, size_);
    }
};
