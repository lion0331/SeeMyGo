#pragma once
#include <iostream>
#include <stdexcept>

template<typename E>
class ArrayList {
public:
    // 构造函数
    ArrayList(int capacity = DEFAULT_CAPACITY) {
        this->capacity = (capacity < DEFAULT_CAPACITY) ? DEFAULT_CAPACITY : capacity;
        elements = new E[this->capacity];
        size = 0;
    }
    // 添加适当的默认构造函数
    ArrayList() : elements(nullptr), size(0), capacity(DEFAULT_CAPACITY) {}

    ~ArrayList() {
        delete[] elements;
    }

    void clear();
    int getSize() const;
    bool isEmpty() const;
    bool contains(const E& element) const;

    E get(int index) const;
    E set(int index, const E& element);
    void add(int index, const E& element);
    E remove(int index);
    int indexOf(const E& element) const;
    void ensureCapacity(int capacity);
    void rangeCheck(int index) const;
    void rangeCheckForAdd(int index) const;

private:
    static const int DEFAULT_CAPACITY = 10;
    E* elements;
    int size;
    int capacity;
    static const int DEFAULT_CAPACITY = 10;
    static const int ELEMENT_NOT_FOUND = -1;

};

