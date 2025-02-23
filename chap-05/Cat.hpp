#pragma once

#include <iostream>
#include <string>

class Cat
{
    friend std::ostream& operator<<(std::ostream& stream, const Cat& cat)
    {
        stream << cat._name;
        return stream;
    }

public:
    Cat() = default;

    Cat(const std::string name)
        : _name { name }
    {}

    ~Cat() { std::cout << _name << " supprime" << std::endl; }

    bool operator==(const Cat& other) { return _name == other._name; }

private:
    std::string _name;
};