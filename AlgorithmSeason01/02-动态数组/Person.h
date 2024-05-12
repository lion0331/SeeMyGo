#pragma once
#include <iostream>
#include <string>

class Person {
private:
    int age;
    std::string name;

public:

    // 使用默认构造函数初始化成员
    Person() : age(0), name("") {}

    // 构造函数
    Person(int age, const std::string& name) : age(age), name(name) {}


    // 析构函数
    ~Person() {
        std::cout << "Person - Destructor called" << std::endl;
    }

    // 用于比较两个 Person 对象的 equals 函数
    bool equals(const Person& other) const;

    // 重载 << 运算符以打印 Person 对象
    friend std::ostream& operator<<(std::ostream& os, const Person& p);


};
