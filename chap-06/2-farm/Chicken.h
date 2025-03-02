#pragma once

#include "Animal.h"

#include <iostream>

class Chicken : public Animal
{
public:
    ~Chicken() override { std::cout << "CotCooooooooot!" << std::endl; }
    void sing(char next_char) const override { std::cout << "Cotcotcotcodet" << next_char; }
};
