//
// Created by Tanner on 9/1/2024.
//

#include "Derived.h"

Derived::Derived()
{
    std::cout << "Derived Class Constructed" << endl;
}
Derived::~Derived()
{
    std::cout << "Derived Class Destroyed" << endl;
    delete basePtr;
}

void Derived::toString() const
{
    std::cout << "Derived::toString()"<< endl;

}

