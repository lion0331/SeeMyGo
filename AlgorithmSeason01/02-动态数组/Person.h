#pragma once
#include <string>
#include <iostream>

class Person
{
private:
    int age;
    std::string name;

public:
    Person() : age(0), name("") {}
    Person(int age, const std::string& name) : age(age), name(name) {}

    int getAge() const { return age; }
    std::string getName() const { return name; }

    bool equals(const Person& other) const;

    // ÖØÔØ == ÔËËã·û
    bool operator==(const Person& other) const
    {
        return age == other.age && name == other.name;
    }

    friend std::ostream& operator<<(std::ostream& os, const Person& p);

    ~Person() {}
};


