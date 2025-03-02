#pragma once

#include "Vehicle.h"

#include <iostream>

class Car : public Vehicle
{
public:
    Car(const Driver& driver, unsigned int speed)
        : Vehicle { driver }
        , _speed { speed }
    {}

    unsigned int drive() const override
    {
        if (!_driver.has_car_licence())
        {
            std::cerr << "No car licence detected..." << std::endl;
            return 0u;
        }
        std::cout << "Vrooooom!" << std::endl;
        return _speed;
    }

private:
    unsigned int _speed = 0;
};
