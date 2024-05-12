#include "Person.h"

    // 用于比较两个 Person 对象的 equals 函数
    bool Person::equals(const Person& other) const {
        // 可以直接访问私有成员，因为这是类的成员函数
        return this->age == other.age;
    }

    // 重载 << 运算符以打印 Person 对象
    std::ostream& operator<<(std::ostream& os, const Person& p) {
        os << "Person [age=" << p.age << ", name=" << p.name << "]";
        return os;
    }
