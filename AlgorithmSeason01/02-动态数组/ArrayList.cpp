#include "ArrayList.h"

template <typename E>  // 在类外部定义函数时包含模板参数列表
void ArrayList<E>::clear() {
    delete[] elements;
    elements = new E[DEFAULT_CAPACITY];
    size = 0;
}

template <typename E>  // 在类外部定义函数时包含模板参数列表
int ArrayList<E>::getSize() const {
    return size;
}

template <typename E>
bool ArrayList<E>::isEmpty() const {
    return size == 0;
}

template <typename E>
bool ArrayList<E>::contains(const E& element) const {
    return indexOf(element) != ELEMENT_NOT_FOUND;
}

template <typename E>
E ArrayList<E>::get(int index) const {
    rangeCheck(index);
    return elements[index];
}

template <typename E>
E ArrayList<E>::set(int index, const E& element) {
    rangeCheck(index);
    E old = elements[index];
    elements[index] = element;
    return old;
}

template <typename E>
void ArrayList<E>::add(int index, const E& element) {
    rangeCheckForAdd(index);
    ensureCapacity(size + 1);

    for (int i = size; i > index; --i) {
        elements[i] = elements[i - 1];
    }
    elements[index] = element;
    ++size;
}

template <typename E>
E ArrayList<E>::remove(int index) {
    rangeCheck(index);
    E old = elements[index];
    for (int i = index + 1; i < size; ++i) {
        elements[i - 1] = elements[i];
    }
    elements[--size] = E(); // Assign a default-constructed object
    return old;
}

template <typename E>
int ArrayList<E>::indexOf(const E& element) const {
    for (int i = 0; i < size; ++i) {
        if (elements[i] == element) {
            return i;
        }
    }
    return ELEMENT_NOT_FOUND;
}

template <typename E>
void ArrayList<E>::ensureCapacity(int capacity) {
    if (capacity > DEFAULT_CAPACITY) {
        int newCapacity = size + (size >> 1);
        E* newElements = new E[newCapacity];
        for (int i = 0; i < size; ++i) {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
        std::cout << "Expanded to " << newCapacity << std::endl;
    }
}

template <typename E>
void ArrayList<E>::rangeCheck(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
}

template <typename E>
void ArrayList<E>::rangeCheckForAdd(int index) const {
    if (index < 0 || index > size) {
        throw std::out_of_range("Index out of bounds for add");
    }
}