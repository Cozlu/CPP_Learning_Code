#include "Cat.hpp"

#include <iostream>
#include <memory>

int main()
{
    std::unique_ptr<Cat> cat = std::make_unique<Cat>("C");
    std::cout << *cat << std::endl;

    std::unique_ptr<Cat> empty;
    std::cout << (empty == nullptr) << std::endl;

    empty = std::make_unique<Cat>("C2");

    std::cout << (empty == cat) << std::endl;
    std::cout << (*empty == *cat) << std::endl;

    cat.reset();
    std::cout << (cat == nullptr) << std::endl;
    return 0;
}