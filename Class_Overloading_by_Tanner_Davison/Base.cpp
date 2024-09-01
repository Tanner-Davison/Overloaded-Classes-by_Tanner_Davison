//
// Created by Tanner on 8/31/2024.
//

#include "Base.h"


Base::Base()
{
    std::cout << "Base Constructed" << std::endl;
}

Base::~Base()
{
    std::cout << "Base Destroyed" << std::endl;
}

void Base::toString() const
{
    cout << "Base::toString() " << endl;
}


