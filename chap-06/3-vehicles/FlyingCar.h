#pragma once

#include "Car.h"
#include "Vehicle.h"

#include <iostream>

class FlyingCar : public Car
{
public:
    FlyingCar(const Driver& driver, unsigned int speed)
        : Car { driver, speed }
        , _flying_speed { 10u * speed }
    {}

    unsigned int drive() const override
    {
        if (!_driver.has_flying_car_licence())
        {
            Car::drive();
        }
        std::cout << "Sweeesh!" << std::endl;
        return _flying_speed;
    }

private:
    unsigned int _flying_speed = 0;
};
