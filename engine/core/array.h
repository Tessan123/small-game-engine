#pragma once

#include <cstddef>

template <typename T>
class Array
{
public:
    Array() : data(nullptr), size(0), capacity(0)
    {
    }

    ~Array()
    {
        delete[] data;
    }

    void PushBack(const T &value)
    {
        if (size >= capacity)
        {
            Rezise();
        }
        data[size] = value;
        size++;
    }

    T &operator[](std::size_t index) const
    {
        return data[index];
    }

    std::size_t Size() const
    {
        return size;
    }

private:
    void Rezise()
    {
        std::size_t newCapacity;

        if (capacity == 0)
        {
            newCapacity = 4;
        }
        else
        {
            newCapacity = capacity * 2;
        }

        T *newData = new T[newCapacity];

        for (std::size_t i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

    T *data;
    std::size_t size;
    std::size_t capacity;
};