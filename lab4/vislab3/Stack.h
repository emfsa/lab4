#pragma once

#include <iostream>
#include <stdexcept>  // Для исключений

template<typename T>
class Stack
{
    T* _data;
    size_t _size;
    size_t _count;

    void Resize()
    {
        size_t newSize = _size * 2;
        T* newData = new T[newSize];
        for (size_t i = 0; i < _count; ++i)
        {
            newData[i] = _data[i];
        }
        delete[] _data;
        _data = newData;
        _size = newSize;
    }

public:
    Stack(size_t size = 8) : _size(size), _count(0)
    {
        _data = new T[_size];
    }

    Stack(const Stack& other) : _size(other._size), _count(other._count)
    {
        _data = new T[_size];
        for (size_t i = 0; i < _count; ++i)
        {
            _data[i] = other._data[i];
        }
    }


    Stack& operator=(const Stack& other)
    {
        if (this == &other) return *this;  // Защита от self-assignment

        delete[] _data;  // Очищаем текущую память

        _size = other._size;
        _count = other._count;
        _data = new T[_size];
        for (size_t i = 0; i < _count; ++i)
        {
            _data[i] = other._data[i];
        }

        return *this;
    }


    void Push(T elem)
    {
        if (_data == nullptr) {
            throw std::runtime_error("Stack is not initialized or was cleared");
        }

        if (_count >= _size)
        {
            Resize();
        }
        _data[_count++] = elem;
    }

    void Pop()
    {
        if (_count > 0)
        {
            --_count;
        }
        else
        {
            throw std::out_of_range("Stack is empty");
        }
    }

    T& Top()
    {
        if (_count == 0)
        {
            throw std::out_of_range("Stack is empty");
        }
        return _data[_count - 1];
    }

    bool isEmpty() const
    {
        return _count == 0;
    }

    size_t getSize() const
    {
        return _count;
    }

    void clearData()
    {
        delete[] _data;
        _data = new T[_size];
    }
    void clear()
    {
        delete[] _data;
        _data = nullptr;
        _count = 0;
    }

    ~Stack()
    {
        clear();
    }
};