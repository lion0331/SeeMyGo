#pragma once
#include <iostream>
#include <stdexcept>
#include "Person.h"

template <typename E>
class ArrayList
{
private:
    E* elements = nullptr;
    int size = 0;
    int capacity = DEFAULT_CAPACITY;
    static const int DEFAULT_CAPACITY = 10;
    static const int ELEMENT_NOT_FOUND = -1;

    void ensureCapacity(int capacity)
    {
        if (capacity > this->capacity)
        {
            int newCapacity = this->capacity + (this->capacity >> 1);
            E* newElements = new E[newCapacity];
            for (int i = 0; i < size; ++i)
            {
                newElements[i] = elements[i];
            }
            delete[] elements;
            elements = newElements;
            this->capacity = newCapacity;
            std::cout << "Expanded to " << newCapacity << std::endl;
        }
    }

    void rangeCheck(int index) const
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Index out of bounds");
        }
    }

    void rangeCheckForAdd(int index) const
    {
        if (index < 0 || index > size)
        {
            throw std::out_of_range("Index out of bounds for add");
        }
    }

public:
    ArrayList() : elements(new E[DEFAULT_CAPACITY]), size(0), capacity(DEFAULT_CAPACITY) {}
    ~ArrayList() { delete[] elements; }

    void clear()
    {
        delete[] elements;
        elements = new E[DEFAULT_CAPACITY];
        size = 0;
    }

    int getSize() const { return size; }

    bool isEmpty() const { return size == 0; }

    bool contains(const E& element) const { return indexOf(element) != ELEMENT_NOT_FOUND; }

    E get(int index) const
    {
        rangeCheck(index);
        return elements[index];
    }

    E set(int index, const E& element)
    {
        rangeCheck(index);
        E old = elements[index];
        elements[index] = element;
        return old;
    }

    void add(int index, const E& element)
    {
        rangeCheckForAdd(index);
        ensureCapacity(size + 1);

        for (int i = size; i > index; --i)
        {
            elements[i] = elements[i - 1];
        }
        elements[index] = element;
        ++size;
    }

    void add(const E& element) { add(size, element); }

    E remove(int index)
    {
        rangeCheck(index);
        E old = elements[index];
        for (int i = index + 1; i < size; ++i)
        {
            elements[i - 1] = elements[i];
        }
        elements[--size] = E(); // Assign a default-constructed object
        return old;
    }

    int indexOf(const E& element) const
    {
        for (int i = 0; i < size; ++i)
        {
            if (elements[i] == element)
            {
                return i;
            }
        }
        return ELEMENT_NOT_FOUND;
    }
};
