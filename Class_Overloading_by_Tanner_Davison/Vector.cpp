//
// Created by Tanner on 8/31/2024.
//

#include "Vector.h"

namespace
{
    void hello(){std::cout << "hello global" << std::endl;}

}


Vector::Vector()
{
    std::cout << "Vector Constructed" << std::endl;
}

Vector::~Vector()
{
    std::cout << "Vector Destroyed" << std::endl;
}

void Vector::toString()
{
    hello();
}
